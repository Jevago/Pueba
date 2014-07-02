#include <generateData.h>

int main( int argc, char **argv )
{
	unsigned int nPoints = 0;
	unsigned int nPointsInFigure = 0;
	unsigned int i = 0;
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	float centro[] = { 0.0, 0.0, 0.0 };
	FILE *fp = NULL;

	if( argc != 2 ){
		printf("Faltan o sobran argumentos al ejecutable\n"); 
		return 1;
	}

	printf("Numero de puntos totales en el conjunto: ");
	scanf( "%u", &nPoints ); fflush( stdin );

	printf("Numero de puntos en la figura: ");
	scanf( "%u", &nPointsInFigure ); fflush( stdin );

	fp = fopen( argv[1], "w" );
	if( !fp ){
		printf("Error al crear el archivo!!!\n");
		return 1;
	}

	fprintf( fp, "%d 3\n", nPoints );

	if( generateSphere( nPointsInFigure, 100.0, centro, fp ) ){
		fclose( fp );
		return 1;
	}

	initializingRandomNum();
	for( i = 0; i < nPoints - nPointsInFigure; i++ ){
		x = generateRandomFloat( X_MIN, X_MAX );
		y = generateRandomFloat( Y_MIN, Y_MAX );
		z = generateRandomFloat( Z_MIN, Z_MAX );
		fprintf( fp, "%f %f %f\n", x, y, z );
	}

	printf("\n\n<<<<<<<<<<<<<<< PROGRAMA TERMINADO >>>>>>>>>>>>>>>\n\n");
	fclose( fp );
	return 0;
}



