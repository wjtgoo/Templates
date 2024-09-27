import logging
import sys
logging.basicConfig(
    level=logging.INFO,
    format='%(asctime)s-%(levelname)s: %(message)s',
    datefmt='%Y-%m-%d %H:%M:%S',
    handlers=[
        logging.FileHandler('log.log'),      # 输出到文件
        logging.StreamHandler(sys.stdout)      # 输出到终端
    ]
)

# 测试输出
logging.info('This is an info message')
logging.error('This is an error message')
