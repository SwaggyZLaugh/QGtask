import pandas as pd
from sklearn.datasets import load_boston

# 导入数据
dataset = load_boston()
dataframe = pd.DataFrame(dataset['data'])
dataframe.columns = dataset['feature_names']
dataframe['price'] = dataset['target']
# 将数据赋值给x和y
x_rm = dataframe['RM'].values
y_price = dataframe['price'].values


class SimpleLinearRegression:
    def __init__(self):
        self.a = None
        self.b = None

    def getab(self, x_data, y_data):
        x_bar = 0
        y_bar = 0
        '''求x和y的均值'''
        for x_i, y_i in zip(x_data, y_data):
            x_bar += x_i
            y_bar += y_i
        x_bar /= len(x_data)
        y_bar /= len(y_data)
        '''求a和b'''
        den = 0.0
        num = 0.0
        for x_i, y_i in zip(x_data, y_data):
            num += (x_i-x_bar)*(y_i-y_bar)
            den += (x_i-x_bar) ** 2
        self.a = num / den
        self.b = y_bar - self.a * x_bar

        return self

    '''求单个x的y_hat'''
    def predict(self, x):
        return self.a * x + self.b

    '''获得全部y_hat'''
    def getyhat(self, x_predict):
        return [self.predict(x) for x in x_predict]

    def __repr__(self):
        return "SimpleLinearRegression"


slr = SimpleLinearRegression()

slr.getab(x_rm, y_price)

print(slr.a, slr.b)

a = eval(input("输入需要预测的x向量组"))
print("预测值为:", slr.getyhat(a))
