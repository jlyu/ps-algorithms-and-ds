#### 树  

通常，可以用来表示 `图`的方法都可以用来表示`数`  


```Python
class Bunch(dict): 
    def __init__(self, *args, **kwds):
        super(Bunch, self).__init__(*args, **kwds)
        self.__dict__ = self

T = Bunch
t = T(left=T(left="a", right="b"), right=T(left="c"))
t.left #{'right':'b', 'left':'a'}
t.left.right #'b'
"left" in t.right #True
"right" in t.right #False
```