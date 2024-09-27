import numpy as np
import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import plotly.graph_objects as go
def plot2Dimage(x_start=0,x_end=128,
                y_start=0,y_end=128,
                dx=1,f=None,
                cmap='RdBu_r',
                title="Wave Field",
                x_label='X',
                y_label='Y',
                figsize=(7,5),
                levels=100):

    x = np.arange(x_start,x_end)*dx
    y = np.arange(y_start,y_end)*dx
    X ,Y = np.meshgrid(x,y,indexing='ij')
    X = X.flatten()
    Y = Y.flatten()
    u = f.flatten()
    fig, ax = plt.subplots(figsize=figsize)
    image = ax.tricontourf(X,Y,u,levels=levels,cmap=cmap)
    cbar = plt.colorbar(image)
    cbar.ax.yaxis.set_major_formatter(ticker.ScalarFormatter(useMathText=True))
    cbar.ax.yaxis.set_major_formatter(ticker.FormatStrFormatter('%.3e'))
    ax.set_title(title)
    ax.set_xlabel(x_label)
    ax.set_ylabel(y_label)
    ax.invert_yaxis()
    plt.show()



def plot_animate(datas, freq=80):
    num_frames = len(datas)
    
    fig = go.Figure(
        data=[go.Heatmap(z=datas[0], colorscale='rdbu_r', zmin=datas.min()*0.1, zmax=datas.max()*0.1)],
        layout=go.Layout(
            title='Wavefield',
            title_x=0.5,
            title_y=0.97, 
            width=500,
            height=500, 
            margin=dict(l=20, r=20, t=45, b=20), 
            updatemenus=[{
                'buttons': [
                    {'args': [None, {'frame': {'duration': freq, 'redraw': True}, 'mode': 'immediate'}],
                    'label': 'Play',
                    'method': 'animate'}
                ],
                'type': 'buttons',
                'x': -0.01,
                'y': -0.2,
            }],
            sliders=[{
                'active': 0,
                'x': 0.,
                'y': 0,
                'steps': [{'args': [[f'{i}'], {'frame': {'duration': 0, 'redraw': True}, 'mode': 'immediate'}],
                        'label': str(i), 'method': 'animate'} for i in range(num_frames)]
            }],
            xaxis=dict(scaleanchor='y', constrain='domain'),  # 使x轴和y轴等比例
            yaxis=dict(constrain='domain')  # 限制y轴范围
        ),
        frames=[go.Frame(data=[go.Heatmap(z=datas[i], colorscale='rdbu_r', zmin=datas.min()*0.1, zmax=datas.max()*0.1)], name=str(i)) for i in range(num_frames)]
    )

    fig.show()