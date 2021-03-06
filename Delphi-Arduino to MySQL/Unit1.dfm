object Read_Value: TRead_Value
  Left = 414
  Top = 227
  Width = 654
  Height = 349
  Caption = 'Read_Arduino'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Latitude: TLabel
    Left = 8
    Top = 124
    Width = 38
    Height = 13
    Caption = 'Latitude'
  end
  object Longitude: TLabel
    Left = 8
    Top = 146
    Width = 47
    Height = 13
    Caption = 'Longitude'
  end
  object Temperature: TLabel
    Left = 8
    Top = 169
    Width = 60
    Height = 13
    Caption = 'Temperature'
  end
  object Humidity: TLabel
    Left = 235
    Top = 124
    Width = 40
    Height = 13
    Caption = 'Humidity'
  end
  object Pressure: TLabel
    Left = 235
    Top = 149
    Width = 41
    Height = 13
    Caption = 'Pressure'
  end
  object Altitude: TLabel
    Left = 235
    Top = 173
    Width = 35
    Height = 13
    Caption = 'Altitude'
  end
  object CBPort: TComComboBox
    Left = 8
    Top = 8
    Width = 145
    Height = 21
    ComPort = ComPort1
    ComProperty = cpPort
    AutoApply = True
    Text = 'COM7'
    Style = csDropDownList
    Ctl3D = False
    ItemHeight = 13
    ItemIndex = 0
    ParentCtl3D = False
    TabOrder = 0
  end
  object ComTerminal1: TComTerminal
    Left = 3
    Top = 36
    Width = 625
    Height = 81
    Color = clGray
    Emulation = teVT100orANSI
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWhite
    Font.Height = -12
    Font.Name = 'Fixedsys'
    Font.Style = []
    ScrollBars = ssNone
    TabOrder = 1
    OnChar = ComTerminal1Char
  end
  object Button1: TButton
    Left = 173
    Top = 6
    Width = 75
    Height = 25
    Caption = 'Open'
    TabOrder = 2
    OnClick = Button1Click
  end
  object elat: TEdit
    Left = 75
    Top = 120
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 3
  end
  object elong: TEdit
    Left = 75
    Top = 144
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 4
  end
  object etemp: TEdit
    Left = 75
    Top = 168
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 5
  end
  object ehum: TEdit
    Left = 298
    Top = 120
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 6
  end
  object epress: TEdit
    Left = 298
    Top = 144
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 7
  end
  object ealt: TEdit
    Left = 298
    Top = 168
    Width = 121
    Height = 21
    ReadOnly = True
    TabOrder = 8
  end
  object DBGrid1: TDBGrid
    Left = 3
    Top = 194
    Width = 630
    Height = 111
    DataSource = DataSource1
    ReadOnly = True
    TabOrder = 9
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'id'
        Title.Alignment = taCenter
        Width = 25
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Waktu'
        Title.Alignment = taCenter
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Latitude'
        Title.Alignment = taCenter
        Width = 53
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Longitude'
        Title.Alignment = taCenter
        Width = 61
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Temperature'
        Title.Alignment = taCenter
        Width = 76
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Humidity'
        Title.Alignment = taCenter
        Width = 47
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Pressure'
        Title.Alignment = taCenter
        Width = 51
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Altitude'
        Title.Alignment = taCenter
        Width = 45
        Visible = True
      end>
  end
  object ComPort1: TComPort
    BaudRate = br9600
    Port = 'COM7'
    Parity.Bits = prNone
    StopBits = sbOneStopBit
    DataBits = dbEight
    Events = [evRxChar, evTxEmpty, evRxFlag, evRing, evBreak, evCTS, evDSR, evError, evRLSD, evRx80Full]
    FlowControl.OutCTSFlow = False
    FlowControl.OutDSRFlow = False
    FlowControl.ControlDTR = dtrDisable
    FlowControl.ControlRTS = rtsDisable
    FlowControl.XonXoffOut = False
    FlowControl.XonXoffIn = False
    StoredProps = []
    TriggersOnRxChar = False
    Left = 262
    Top = 4
  end
  object ComDataPacket1: TComDataPacket
    ComPort = ComPort1
    Left = 294
    Top = 4
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 326
    Top = 4
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'SELECT * FROM `skripsi` ORDER BY `id` DESC ')
    Left = 422
    Top = 4
  end
  object ADOConnection1: TADOConnection
    Connected = True
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source=Peman' +
      'tau_db'
    LoginPrompt = False
    Left = 358
    Top = 4
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 390
    Top = 4
  end
end
