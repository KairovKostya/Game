Карта сделана singleton-ом, так как это один единственный объект
Генератор - это фабрика, умеющая создавать объекты.
Все классы объектов - наследники абстрактного класса Object

Весь смысл - уворачиваться от метеоритов. 
Есть класс декоратор, который отвечает за создание разных типов астеройдов. 
Есть класс подписчик, и publisher, которые отвечают за сообщение подписчикам (асеторойдам и главному кораблю), что был нанесён урон. Корабль после получения урона перекрашивается в красный, а астеройды, находящиеся на поле, на несколько секунд останавливаются.