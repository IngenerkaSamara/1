const canvas = document.getElementById('game');
const ctx = canvas.getContext("2d");

const step = 30;

const background = new Image();
background.src = "Pics/fonsnake.jpg";

const snakehead = new Image();
snakehead.src = "Pics/headsnake.jpg";
const snakebody = new Image();
snakebody.src = "Pics/bodysnake.png";
let snake = []
snake [0] =
{
	x: 4 * step,
	y: 6 * step,
};

let dir = "";
document.addEventListener("keydown", getDirection);
function getDirection()
{
		if(event.keyCode == 37)
	{
		dir="L";
	}
		if(event.keyCode == 38)
	{
		dir="U";
	}
		if(event.keyCode == 39)
	{
		dir="R";
	}
		if(event.keyCode == 40)
	{
		dir="D";
	}

		if(event.keyCode == 65)
	{
		dir="LA";
	}
		if(event.keyCode == 87)
	{
		dir="LW";
	}
		if(event.keyCode == 68)
	{
		dir="LD";
	}
		if(event.keyCode == 83)
	{
		dir="LS";
	}

}





const snakefood = new Image();
snakefood.src = "Pics/foodsnake.jpg";
let snakefoodX = Math.floor(Math.random() * 600 / step )* step;
let snakefoodY = Math.floor(Math.random() * 600 / step )* step;



let game = setInterval(drawGame, 100);

function drawGame()
{
	ctx.drawImage(background, 0, 0);	
	ctx.drawImage(snakefood , snakefoodX, snakefoodY);

	for (let i = 1; i < snake.length; i += 1)
	{	
		ctx.drawImage(snakebody , snake [i].x, snake [i].y);
		//ctx.fillRect(snake [i].x, snake [i].y, step, step);
	}
	ctx.drawImage(snakehead , snake [0].x, snake [0].y);
	
	let snakeX = snake[0].x;
	let snakeY = snake[0].y;

	if (snakeX == snakefoodX && snakeY == snakefoodY)
	{
		snakefoodX = Math.floor(Math.random() * 600 / step )* step;
		snakefoodY = Math.floor(Math.random() * 600 / step )* step;
	}
	else snake.pop();

	if (dir == "L") snakeX-= step;
	if (dir == "LA") snakeX-= step;
	if (dir == "R") snakeX+= step;
	if (dir == "LD") snakeX+= step;
	if (dir == "U") snakeY-= step;
	if (dir == "LW") snakeY-= step;
	if (dir == "D") snakeY+= step;
	if (dir == "LS") snakeY+= step;

	let newHead =
	{
		x: snakeX,
		y: snakeY,

	};

	snake.unshift(newHead);
}