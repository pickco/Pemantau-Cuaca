unit Unit1;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, ExtCtrls, CPortCtl, StdCtrls, CPort, Grids, DBGrids, DB, ADODB;

type
  TRead_Value = class(TForm)
    ComPort1: TComPort;
    ComDataPacket1: TComDataPacket;
    ComTerminal1: TComTerminal;
    Timer1: TTimer;
    Button1: TButton;
    CBPort: TComComboBox;
    Latitude: TLabel;
    Longitude: TLabel;
    Temperature: TLabel;
    Humidity: TLabel;
    Pressure: TLabel;
    Altitude: TLabel;
    elat: TEdit;
    elong: TEdit;
    etemp: TEdit;
    ehum: TEdit;
    epress: TEdit;
    ealt: TEdit;
    ADOQuery1: TADOQuery;
    ADOConnection1: TADOConnection;
    DataSource1: TDataSource;
    DBGrid1: TDBGrid;
    procedure ComTerminal1Char(Sender: TObject; Ch: Char);
    procedure Button1Click(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Read_Value: TRead_Value;
  strnya, weiginstring: string;
  kon : integer;

implementation

{$R *.dfm}


Function StrToHex(s: String): String;
Var
  i : Integer;
Begin
  Result:='';
  If Length(s)>0 Then
    For i:=1 To Length(s) Do Result:=Result+IntToHex(Ord(s[i]),2);
End;

Function HexToAscii(Hex: String): String;
begin
   result := chr(StrToInt('$'+hex));
end;

function StringToHex(S: String): string;
var I: Integer;
begin
  Result:= '';
  for I := 1 to length (S) do
    Result:= Result+IntToHex(ord(S[i]),2);
end;

procedure TRead_Value.ComTerminal1Char(Sender: TObject; Ch: Char);
begin
   if StringToHex(Ch) = '0A' then
    begin
     weiginstring:=strnya;
     if weiginstring <> '' then
      begin
       strnya:='';

      end;
    end
   else
    begin
     strnya:=strnya+ch;
    end;
end;

procedure TRead_Value.Button1Click(Sender: TObject);
begin
if Button1.Caption = 'Close' then
  begin
    ComPort1.Connected:=false;
    //ComPort1.Open;
    ComTerminal1.ClearScreen;
    Timer1.Enabled:=false;
    CBPort.Enabled:=true;
    Button1.Caption:='Open';
    exit;
  end
 else
  begin
   Timer1.Enabled:=true;
   ComTerminal1.ClearScreen;
   ComTerminal1.ComPort:=CBPort.ComPort;
   ComPort1.Connected:=true;
   //ComPort1.Close;
   CBPort.Enabled:=false;
   Button1.Caption :='Close';
  end
end;

procedure TRead_Value.Timer1Timer(Sender: TObject);
var
 s : String;
 sl: TStringList;
begin

try
if ComPort1.Connected = true then
  begin
    if (weiginstring <> '') and (weiginstring <> 'Terputus') then
      begin
      sl := TStringList.Create;
      s := weiginstring;
      elat.Clear;
      elong.Clear;
      etemp.Clear;
      ehum.Clear;
      epress.Clear;
      ealt.Clear;

    if s <> 'Terputus' then
     begin
        sl.Delimiter := ',';
        sl.DelimitedText := s;
      end;
    if sl.DelimitedText <> '' then
      begin
       elat.Text:=sl[0];
      end;
    if sl.DelimitedText <> '' then
      begin
        elong.Text:=sl[1];
      end;
    if sl.DelimitedText <> '' then
      begin
        etemp.Text:=sl[2];
      end;
    if sl.DelimitedText <> '' then
      begin
        ehum.Text:=sl[3];
      end;
    if sl.DelimitedText <> '' then
      begin
        epress.Text:=sl[4];
      end;
    if sl.DelimitedText <> '' then
      begin
        ealt.Text:=sl[5];
      end;


with ADOQuery1 do
  begin
    Close;
     SQL.Clear;
     SQL.Add('INSERT INTO skripsi ( Latitude, Longitude, Temperature, Humidity, Pressure, Altitude) ');
     SQL.Add('VALUES ('+elat.Text+', '+elong.Text+', '+etemp.Text+', '+ehum.Text+', '+epress.Text+', '+ealt.Text+') ');
     ExecSQL;
     SQL.Clear;
     SQL.Add('SELECT * FROM skripsi ORDER BY id DESC');
     Open;
    end;
    end;
   end;
   except
  end;

end;


end.
