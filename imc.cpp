#include "imc.h"
#include "ui_imc.h"

imc::imc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::imc)
{
    ui->setupUi(this);
    QString filename = " ";

    QFile file(filename);
    curfile = filename;
    if(file.exists()){

        qDebug()<<" ";

        //SI EL ARCHIVO EXISTE ENTRA ACA
        if(file.open( QFile::ReadOnly | QFile::Text)){
            qDebug()<<"aaasdfdsdgfd";

            QTextStream entrada(&file);
            while(!entrada.atEnd()){
                qDebug()<<" ";

                QString linea = entrada.readLine();
                QVector<QStringRef>datos = linea.splitRef("\t");
                qDebug()<<datos.size();
                QString fecha = datos.at(0).toString();
                QString estatura = datos.at(1).toString();
                QString peso = datos.at(2).toString();
                QString imc = datos.at(3).toString();


                m_lista.append(new principal(imc.toFloat(),peso.toFloat(),fecha,estatura.toFloat()));

            }
            foreach(principal *p, m_lista){
                qDebug()<<p->peso()<<endl;
            }

            ordenar();
            qDebug()<<" "<<endl;
            foreach(principal *p, m_lista){
                qDebug()<<p->peso()<<endl;
            }

            ui->outPM->setText(QString::number(m_lista.at(m_lista.length()-1)->peso(),'f',2) + " kg");
            ui->outPMIN->setText(QString::number(m_lista.at(0)->peso(),'f',2) + " kg");
        }

    }

    file.close();
}

imc::~imc()
{
    delete ui;
}



void imc::on_btCalcular_released()
{
    if(obtenerDatos()){
        calcular();
        m_lista.append(new principal(m_imc,m_peso,m_fecha,m_estatura));
        moverLinea(m_imc);
        ordenar();
        ui->outPM->setText(QString::number(m_lista.at(m_lista.length()-1)->peso(),'f',2) + " kg");
        ui->outPMIN->setText(QString::number(m_lista.at(0)->peso(),'f',2) + " kg");


        m_datos += m_fecha + "\t" + QString::number(m_estatura,'f',2) + "\t" +  QString::number(m_peso,'f',2) + "\t" + QString::number(m_imc,'f',2) + "\n";
        savefile();

    }else{
        ui->statusbar->showMessage("Campo vacio",3000);
    }

}

void imc::savefile()
{

    //QFile file(curfile);
    QFile archivo(QDir::currentPath()+"/../IMC/registro/informe.txt");
    /*if(file.open(QFile::WriteOnly)){
        file.write(m_datos.toUtf8());
    }else{
        qDebug()<<"N";
    }
    file.close();*/
    if(archivo.open(QFile::WriteOnly | QFile::Truncate)){
    QTextStream salida(&archivo);
    salida.operator<<("\n REGISTRO DE IMC\n");
    salida.operator<<("\n___________________________________________________________________\n");
    salida.operator<<( ""+m_datos+"\t\t");

    }else{
        QMessageBox::warning(this,
                             "Guardar datos",
                             "No se pudo guardar el archivo");

    }


    archivo.close();

}

void imc::calcular()
{
    qDebug()<<m_peso;
    qDebug()<<m_estatura;


    m_imc = (m_peso)/qPow(m_estatura,2);

    qDebug()<<m_imc;
    ui->outTIMC->setText(QString::number(m_imc,'f',2) + " kg");
    if(m_imc < 18.5){
        ui->outimc->setText("Peso inferior al normal");
    }else if(m_imc < 24.9){
        ui->outimc->setText("Normal");
    }else if(m_imc < 29.9){
        ui->outimc->setText("Peso superior al normal");
    }else if(m_imc >=30){
        ui->outimc->setText("Obesidad");
    }

    qDebug()<<m_fecha;

}

bool imc::obtenerDatos()
{
    if(ui->intEstatura->text().isEmpty()){
        return false;
    }
    if(ui->intPeso->text().isEmpty()){
        return false;
    }
    m_fecha = ui->intFecha->text();
    m_peso = ui->intPeso->text().toFloat();
    float centi = ui->intEstatura->text().toInt();
    m_estatura = centi/100;

    ui->outPA->setText(QString::number(m_peso) + " kg");
    return true;
}

void imc::ordenar()
{
    for(int j=0; j < m_lista.length(); j++){
        for(int i=0; i < m_lista.length(); i++){
            if(m_lista[j]->imc() < m_lista[i]->imc()){
                principal *temp = m_lista[j];
                m_lista[j] = m_lista[i];
                m_lista[i] = temp;
            }
        }
    }
}

void imc::moverLinea(float principal)
{
    if(principal <=12){
        ui->outLinea->setGeometry(12,0,4,58);
    }else if(principal <= 14){
        ui->outLinea->setGeometry(33,0,4,58);
    }else if(principal <= 16){
        ui->outLinea->setGeometry(57,0,4,58);
    }else if(principal <= 18.5){
        ui->outLinea->setGeometry(75,0,4,58);


    }else if(principal <= 20){
        ui->outLinea->setGeometry(92,0,4,58);
    }else if(principal <= 22){
        ui->outLinea->setGeometry(110,0,4,58);
    }else if(principal <= 23){
        ui->outLinea->setGeometry(134,0,4,58);
    }else if(principal <= 24.5){
        ui->outLinea->setGeometry(154,0,4,58);



    }else if(principal <= 25){
        ui->outLinea->setGeometry(172,0,4,58);
    }else if(principal <= 26){
        ui->outLinea->setGeometry(194,0,4,58);
    }else if(principal <= 28){
        ui->outLinea->setGeometry(220,0,4,58);
    }else if(principal <= 29.9){
        ui->outLinea->setGeometry(244,0,4,58);


    }else if(principal <= 34){
        ui->outLinea->setGeometry(262,0,4,58);
    }else if(principal <= 38){
        ui->outLinea->setGeometry(280,0,4,58);
    }else if(principal >38){
        ui->outLinea->setGeometry(334,0,4,58);
    }

}


