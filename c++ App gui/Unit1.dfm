object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 655
  ClientWidth = 986
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Bevel1: TBevel
    Left = 64
    Top = 104
    Width = 377
    Height = 369
  end
  object Bevel2: TBevel
    Left = 512
    Top = 104
    Width = 393
    Height = 369
  end
  object Temp: TLabel
    Left = 176
    Top = 184
    Width = 72
    Height = 13
    Caption = 'Temperature : '
  end
  object Humid: TLabel
    Left = 176
    Top = 264
    Width = 48
    Height = 13
    Caption = 'Humidit'#233' :'
  end
  object press: TLabel
    Left = 176
    Top = 336
    Width = 47
    Height = 13
    Caption = 'Pression :'
  end
  object Edit1: TEdit
    Left = 64
    Top = 46
    Width = 217
    Height = 21
    TabOrder = 0
    Text = '172.20.21.22'
  end
  object Button1: TButton
    Left = 584
    Top = 44
    Width = 249
    Height = 25
    Caption = 'Scurter'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Edit2: TEdit
    Left = 336
    Top = 46
    Width = 161
    Height = 23
    ReadOnly = True
    TabOrder = 2
    Text = 'F276DD7951'
  end
  object TrackBar1: TTrackBar
    Left = 520
    Top = 184
    Width = 385
    Height = 45
    TabOrder = 3
  end
  object TrackBar2: TTrackBar
    Left = 520
    Top = 264
    Width = 385
    Height = 45
    TabOrder = 4
  end
  object Button2: TButton
    Left = 672
    Top = 344
    Width = 105
    Height = 73
    Caption = '0'
    TabOrder = 5
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 904
    Top = 584
  end
end
