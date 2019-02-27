program Project1;

uses
  Forms,
  Unit1 in 'Unit1.pas' {Read_Value};

{$R *.res}

begin
  Application.Initialize;
  Application.CreateForm(TRead_Value, Read_Value);
  Application.Run;
end.
