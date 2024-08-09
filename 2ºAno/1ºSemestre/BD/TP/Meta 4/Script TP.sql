/*==============================================================*/
/* DBMS name:      ORACLE Version 11g                           */
/* Created on:     16/12/2023 00:39:56                          */
/*==============================================================*/


alter table ACEITE
   drop constraint FK_ACEITE_ACEITAR2_INDIVIDU;

alter table ACEITE
   drop constraint FK_ACEITE_ACEITAR3_VAGAS_DE;

alter table ANUNCIA
   drop constraint FK_ANUNCIA_ANUNCIA_EMPRESA;

alter table ANUNCIA
   drop constraint FK_ANUNCIA_ANUNCIA2_PUBLICAC;

alter table CANDIDATAR_SE
   drop constraint FK_CANDIDAT_CANDIDATA_INDIVIDU;

alter table CANDIDATAR_SE
   drop constraint FK_CANDIDAT_CANDIDATA_VAGAS_DE;

alter table CONEXOES_PROFISSIONAIS
   drop constraint FK_CONEXOES_ACEITAR_INDIVIDU;

alter table CONEXOES_PROFISSIONAIS
   drop constraint FK_CONEXOES_INICIAR_INDIVIDU;

alter table EMPRESA
   drop constraint FK_EMPRESA_HERANCA2_UTILIZAD;

alter table FORMACAO_ACADEMICA
   drop constraint FK_FORMACAO_POSSUI_INDIVIDU;

alter table FORMACAO_ACADEMICA
   drop constraint FK_FORMACAO_REALIZAR_INSTITUI;

alter table INDIVIDUO
   drop constraint FK_INDIVIDU_HERANCA_UTILIZAD;

alter table PUBLICACAO
   drop constraint FK_PUBLICAC_ASSOCIADA_AREA;

alter table PUBLICACAO
   drop constraint FK_PUBLICAC_CRIAR_INDIVIDU;

alter table REQUISITOS
   drop constraint FK_REQUISIT_NECESSITA_VAGAS_DE;

alter table TEM
   drop constraint FK_TEM_TEM2_INDIVIDU;

alter table TEM
   drop constraint FK_TEM_TEM3_CONEXOES;

alter table VAGAS_DE_EMPREGO
   drop constraint FK_VAGAS_DE_OFERECE_EMPRESA;

drop index RELATIONSHIP_5_FK;

drop index RELATIONSHIP_4_FK;

drop table ACEITE cascade constraints;

drop index ANUNCIA2_FK;

drop index ANUNCIA_FK;

drop table ANUNCIA cascade constraints;

drop table AREA cascade constraints;

drop index CANDIDATAR_SE2_FK;

drop index CANDIDATAR_SE_FK;

drop table CANDIDATAR_SE cascade constraints;

drop index ACEITAR_FK;

drop index INICIAR_FK;

drop table CONEXOES_PROFISSIONAIS cascade constraints;

drop table EMPRESA cascade constraints;

drop index REALIZAR_FK;

drop index POSSUI_FK;

drop table FORMACAO_ACADEMICA cascade constraints;

drop table INDIVIDUO cascade constraints;

drop table INSTITUICAO cascade constraints;

drop index ASSOCIADA_FK;

drop index CRIAR_FK;

drop table PUBLICACAO cascade constraints;

drop index NECESSITA_FK;

drop table REQUISITOS cascade constraints;

drop index RELATIONSHIP_7_FK;

drop table TEM cascade constraints;

drop table UTILIZADOR cascade constraints;

drop index OFERECE_FK;

drop table VAGAS_DE_EMPREGO cascade constraints;

/*==============================================================*/
/* Table: ACEITE                                                */
/*==============================================================*/
create table ACEITE 
(
   ID_UTILIZADOR        NUMBER(10)           not null,
   CODIGO_VAGA          NUMBER(10)           not null,
   constraint PK_ACEITE primary key (ID_UTILIZADOR, CODIGO_VAGA)
);

/*==============================================================*/
/* Index: RELATIONSHIP_4_FK                                     */
/*==============================================================*/
create index RELATIONSHIP_4_FK on ACEITE (
   ID_UTILIZADOR ASC
);

/*==============================================================*/
/* Index: RELATIONSHIP_5_FK                                     */
/*==============================================================*/
create index RELATIONSHIP_5_FK on ACEITE (
   CODIGO_VAGA ASC
);

/*==============================================================*/
/* Table: ANUNCIA                                               */
/*==============================================================*/
create table ANUNCIA 
(
   ID_UTILIZADOR        NUMBER(10)           not null,
   ID_PUBLICACAO        NUMBER(10)           not null,
   constraint PK_ANUNCIA primary key (ID_UTILIZADOR, ID_PUBLICACAO)
);

/*==============================================================*/
/* Index: ANUNCIA_FK                                            */
/*==============================================================*/
create index ANUNCIA_FK on ANUNCIA (
   ID_UTILIZADOR ASC
);

/*==============================================================*/
/* Index: ANUNCIA2_FK                                           */
/*==============================================================*/
create index ANUNCIA2_FK on ANUNCIA (
   ID_PUBLICACAO ASC
);

/*==============================================================*/
/* Table: AREA                                                  */
/*==============================================================*/
create table AREA 
(
   CODIGO_AREA          NUMBER(10)           not null,
   DESIGNACAO           VARCHAR2(30)         not null,
   constraint PK_AREA primary key (CODIGO_AREA)
);

/*==============================================================*/
/* Table: CANDIDATAR_SE                                         */
/*==============================================================*/
create table CANDIDATAR_SE 
(
   ID_UTILIZADOR        NUMBER(10)           not null,
   CODIGO_VAGA          NUMBER(10)           not null,
   DATA_CAND            DATE,
   ESTADO_CAND          VARCHAR2(20),
   constraint PK_CANDIDATAR_SE primary key (ID_UTILIZADOR, CODIGO_VAGA)
);

/*==============================================================*/
/* Index: CANDIDATAR_SE_FK                                      */
/*==============================================================*/
create index CANDIDATAR_SE_FK on CANDIDATAR_SE (
   ID_UTILIZADOR ASC
);

/*==============================================================*/
/* Index: CANDIDATAR_SE2_FK                                     */
/*==============================================================*/
create index CANDIDATAR_SE2_FK on CANDIDATAR_SE (
   CODIGO_VAGA ASC
);

/*==============================================================*/
/* Table: CONEXOES_PROFISSIONAIS                                */
/*==============================================================*/
create table CONEXOES_PROFISSIONAIS 
(
   CODIGO_CONEXAO       NUMBER(10)           not null,
   ID_UTILIZADOR        NUMBER(10),
   DATA                 DATE,
   COMENTARIOS          VARCHAR2(50),
   constraint PK_CONEXOES_PROFISSIONAIS primary key (CODIGO_CONEXAO)
);

/*==============================================================*/
/* Index: INICIAR_FK                                            */
/*==============================================================*/
create index INICIAR_FK on CONEXOES_PROFISSIONAIS (
   ID_UTILIZADOR ASC
);

/*==============================================================*/
/* Index: ACEITAR_FK                                            */
/*==============================================================*/
create index ACEITAR_FK on CONEXOES_PROFISSIONAIS (
   ID_UTILIZADOR ASC
);

/*==============================================================*/
/* Table: EMPRESA                                               */
/*==============================================================*/
create table EMPRESA 
(
   ID_UTILIZADOR        NUMBER(10)           not null,
   constraint PK_EMPRESA primary key (ID_UTILIZADOR)
);

/*==============================================================*/
/* Table: FORMACAO_ACADEMICA                                    */
/*==============================================================*/
create table FORMACAO_ACADEMICA 
(
   CODIGO_FORMACAO      NUMBER(10)           not null,
   CODIGO_INSTITUICAO   NUMBER(10),
   ID_UTILIZADOR        NUMBER(10),
   NOME                 VARCHAR2(30)         not null,
   DATA_CONCLUSAO       DATE,
   constraint PK_FORMACAO_ACADEMICA primary key (CODIGO_FORMACAO)
);

/*==============================================================*/
/* Index: POSSUI_FK                                             */
/*==============================================================*/
create index POSSUI_FK on FORMACAO_ACADEMICA (
   ID_UTILIZADOR ASC
);

/*==============================================================*/
/* Index: REALIZAR_FK                                           */
/*==============================================================*/
create index REALIZAR_FK on FORMACAO_ACADEMICA (
   CODIGO_INSTITUICAO ASC
);

/*==============================================================*/
/* Table: INDIVIDUO                                             */
/*==============================================================*/
create table INDIVIDUO 
(
   ID_UTILIZADOR        NUMBER(10)           not null,
   constraint PK_INDIVIDUO primary key (ID_UTILIZADOR)
);

/*==============================================================*/
/* Table: INSTITUICAO                                           */
/*==============================================================*/
create table INSTITUICAO 
(
   CODIGO_INSTITUICAO   NUMBER(10)           not null,
   RUA                  VARCHAR2(30),
   NUMERO               NUMBER(5),
   DESIGNACAO           VARCHAR2(30)         not null,
   constraint PK_INSTITUICAO primary key (CODIGO_INSTITUICAO)
);

/*==============================================================*/
/* Table: PUBLICACAO                                            */
/*==============================================================*/
create table PUBLICACAO 
(
   ID_PUBLICACAO        NUMBER(10)           not null,
   CODIGO_AREA          NUMBER(10),
   ID_UTILIZADOR        NUMBER(10),
   DATA_PUB             DATE,
   TEXTO                CHAR(50),
   constraint PK_PUBLICACAO primary key (ID_PUBLICACAO)
);

/*==============================================================*/
/* Index: CRIAR_FK                                              */
/*==============================================================*/
create index CRIAR_FK on PUBLICACAO (
   ID_UTILIZADOR ASC
);

/*==============================================================*/
/* Index: ASSOCIADA_FK                                          */
/*==============================================================*/
create index ASSOCIADA_FK on PUBLICACAO (
   CODIGO_AREA ASC
);

/*==============================================================*/
/* Table: REQUISITOS                                            */
/*==============================================================*/
create table REQUISITOS 
(
   CODIGO_REQUISITO     NUMBER(10)           not null,
   CODIGO_VAGA          NUMBER(10),
   DESCRICAO_REQ        VARCHAR2(50)         not null,
   constraint PK_REQUISITOS primary key (CODIGO_REQUISITO)
);

/*==============================================================*/
/* Index: NECESSITA_FK                                          */
/*==============================================================*/
create index NECESSITA_FK on REQUISITOS (
   CODIGO_VAGA ASC
);

/*==============================================================*/
/* Table: TEM                                                   */
/*==============================================================*/
create table TEM 
(
   ID_UTILIZADOR        NUMBER(10)           not null,
   CODIGO_CONEXAO       NUMBER(10)           not null,
   PROPOSITO            VARCHAR2(50)         not null,
   constraint PK_TEM primary key (ID_UTILIZADOR)
);

/*==============================================================*/
/* Index: RELATIONSHIP_7_FK                                     */
/*==============================================================*/
create index RELATIONSHIP_7_FK on TEM (
   CODIGO_CONEXAO ASC
);

/*==============================================================*/
/* Table: UTILIZADOR                                            */
/*==============================================================*/
create table UTILIZADOR 
(
   ID_UTILIZADOR        NUMBER(10)           not null,
   RUA                  VARCHAR2(30),
   NUMERO               NUMBER(5),
   PAIS                 VARCHAR2(20),
   NOME                 VARCHAR2(30)         not null,
   EMAIL                VARCHAR2(50),
   NUM_TELE             NUMBER(9),
   constraint PK_UTILIZADOR primary key (ID_UTILIZADOR)
);

/*==============================================================*/
/* Table: VAGAS_DE_EMPREGO                                      */
/*==============================================================*/
create table VAGAS_DE_EMPREGO 
(
   CODIGO_VAGA          NUMBER(10)           not null,
   ID_UTILIZADOR        NUMBER(10),
   DESCRICAO            VARCHAR2(30),
   PAIS                 VARCHAR2(20),
   constraint PK_VAGAS_DE_EMPREGO primary key (CODIGO_VAGA)
);

/*==============================================================*/
/* Index: OFERECE_FK                                            */
/*==============================================================*/
create index OFERECE_FK on VAGAS_DE_EMPREGO (
   ID_UTILIZADOR ASC
);

alter table ACEITE
   add constraint FK_ACEITE_ACEITAR2_INDIVIDU foreign key (ID_UTILIZADOR)
      references INDIVIDUO (ID_UTILIZADOR);

alter table ACEITE
   add constraint FK_ACEITE_ACEITAR3_VAGAS_DE foreign key (CODIGO_VAGA)
      references VAGAS_DE_EMPREGO (CODIGO_VAGA);

alter table ANUNCIA
   add constraint FK_ANUNCIA_ANUNCIA_EMPRESA foreign key (ID_UTILIZADOR)
      references EMPRESA (ID_UTILIZADOR);

alter table ANUNCIA
   add constraint FK_ANUNCIA_ANUNCIA2_PUBLICAC foreign key (ID_PUBLICACAO)
      references PUBLICACAO (ID_PUBLICACAO);

alter table CANDIDATAR_SE
   add constraint FK_CANDIDAT_CANDIDATA_INDIVIDU foreign key (ID_UTILIZADOR)
      references INDIVIDUO (ID_UTILIZADOR);

alter table CANDIDATAR_SE
   add constraint FK_CANDIDAT_CANDIDATA_VAGAS_DE foreign key (CODIGO_VAGA)
      references VAGAS_DE_EMPREGO (CODIGO_VAGA);

alter table CONEXOES_PROFISSIONAIS
   add constraint FK_CONEXOES_ACEITAR_INDIVIDU foreign key (ID_UTILIZADOR)
      references INDIVIDUO (ID_UTILIZADOR);

alter table CONEXOES_PROFISSIONAIS
   add constraint FK_CONEXOES_INICIAR_INDIVIDU foreign key (ID_UTILIZADOR)
      references INDIVIDUO (ID_UTILIZADOR);

alter table EMPRESA
   add constraint FK_EMPRESA_HERANCA2_UTILIZAD foreign key (ID_UTILIZADOR)
      references UTILIZADOR (ID_UTILIZADOR);

alter table FORMACAO_ACADEMICA
   add constraint FK_FORMACAO_POSSUI_INDIVIDU foreign key (ID_UTILIZADOR)
      references INDIVIDUO (ID_UTILIZADOR);

alter table FORMACAO_ACADEMICA
   add constraint FK_FORMACAO_REALIZAR_INSTITUI foreign key (CODIGO_INSTITUICAO)
      references INSTITUICAO (CODIGO_INSTITUICAO);

alter table INDIVIDUO
   add constraint FK_INDIVIDU_HERANCA_UTILIZAD foreign key (ID_UTILIZADOR)
      references UTILIZADOR (ID_UTILIZADOR);

alter table PUBLICACAO
   add constraint FK_PUBLICAC_ASSOCIADA_AREA foreign key (CODIGO_AREA)
      references AREA (CODIGO_AREA);

alter table PUBLICACAO
   add constraint FK_PUBLICAC_CRIAR_INDIVIDU foreign key (ID_UTILIZADOR)
      references INDIVIDUO (ID_UTILIZADOR);

alter table REQUISITOS
   add constraint FK_REQUISIT_NECESSITA_VAGAS_DE foreign key (CODIGO_VAGA)
      references VAGAS_DE_EMPREGO (CODIGO_VAGA);

alter table TEM
   add constraint FK_TEM_TEM2_INDIVIDU foreign key (ID_UTILIZADOR)
      references INDIVIDUO (ID_UTILIZADOR);

alter table TEM
   add constraint FK_TEM_TEM3_CONEXOES foreign key (CODIGO_CONEXAO)
      references CONEXOES_PROFISSIONAIS (CODIGO_CONEXAO);

alter table VAGAS_DE_EMPREGO
   add constraint FK_VAGAS_DE_OFERECE_EMPRESA foreign key (ID_UTILIZADOR)
      references EMPRESA (ID_UTILIZADOR);

