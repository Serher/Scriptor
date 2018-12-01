object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 649
  ClientWidth = 1076
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Times New Roman'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesigned
  DesignSize = (
    1076
    649)
  PixelsPerInch = 96
  TextHeight = 21
  object CB1: TComboBox
    Left = 8
    Top = 8
    Width = 409
    Height = 29
    Style = csDropDownList
    TabOrder = 0
    OnChange = CB1Change
  end
  object RE1: TRichEdit
    Left = 8
    Top = 43
    Width = 409
    Height = 459
    Anchors = [akLeft, akTop, akBottom]
    BevelOuter = bvNone
    BevelKind = bkFlat
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = []
    Lines.Strings = (
      'RE1')
    ParentFont = False
    ReadOnly = True
    ScrollBars = ssBoth
    TabOrder = 1
    Zoom = 100
    OnChange = RE1Change
    ExplicitHeight = 480
  end
  object Button1: TButton
    Left = 448
    Top = 61
    Width = 81
    Height = 37
    Caption = 'Button1 sdfsdf sdfsdfsd fghfghfhfghfh'
    Style = bsCommandLink
    TabOrder = 2
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object RE3: TRichEdit
    Left = 161
    Top = 508
    Width = 256
    Height = 97
    Anchors = [akLeft, akBottom]
    Lines.Strings = (
      'RE3')
    ScrollBars = ssBoth
    TabOrder = 3
    Zoom = 100
    ExplicitTop = 529
  end
  object BitBtn1: TBitBtn
    Left = 8
    Top = 505
    Width = 137
    Height = 35
    Anchors = [akLeft, akBottom]
    Caption = #1053#1072#1079#1072#1076
    Kind = bkIgnore
    NumGlyphs = 2
    TabOrder = 4
    OnClick = BitBtn1Click
    ExplicitTop = 526
  end
  object Button2: TButton
    Left = 448
    Top = 66
    Width = 81
    Height = 37
    Caption = 'Button1'
    Style = bsCommandLink
    TabOrder = 5
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 448
    Top = 66
    Width = 81
    Height = 37
    Caption = 'Button1 sdfsdf sdfsdfsd fghfghfhfghfh'
    Style = bsCommandLink
    TabOrder = 6
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object Button4: TButton
    Left = 448
    Top = 66
    Width = 81
    Height = 37
    Caption = 'Button1 sdfsdf sdfsdfsd fghfghfhfghfh'
    Style = bsCommandLink
    TabOrder = 7
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object Button5: TButton
    Left = 448
    Top = 66
    Width = 81
    Height = 37
    Caption = 'Button1 sdfsdf sdfsdfsd fghfghfhfghfh'
    Style = bsCommandLink
    TabOrder = 8
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object Button6: TButton
    Left = 448
    Top = 66
    Width = 81
    Height = 37
    Caption = 'Button1 sdfsdf sdfsdfsd fghfghfhfghfh'
    Style = bsCommandLink
    TabOrder = 9
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object Button7: TButton
    Left = 448
    Top = 66
    Width = 81
    Height = 37
    Caption = 'Button1 sdfsdf sdfsdfsd fghfghfhfghfh'
    Style = bsCommandLink
    TabOrder = 10
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object Button8: TButton
    Left = 448
    Top = 66
    Width = 81
    Height = 37
    Caption = 'Button1 sdfsdf sdfsdfsd fghfghfhfghfh'
    Style = bsCommandLink
    TabOrder = 11
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object Button9: TButton
    Left = 440
    Top = 44
    Width = 81
    Height = 37
    Caption = 'Button1 sdfsdf sdfsdfsd fghfghfhfghfh'
    Style = bsCommandLink
    TabOrder = 12
    Visible = False
    WordWrap = True
    OnClick = Button1Click
  end
  object Bt2: TButton
    Left = 440
    Top = 8
    Width = 242
    Height = 30
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1088#1077#1087#1083#1080#1082#1091' '#1072#1073#1086#1085#1077#1085#1090#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
    TabOrder = 14
    Visible = False
    OnClick = Bt2Click
  end
  object TV1: TTreeView
    Left = 576
    Top = 395
    Width = 217
    Height = 145
    Indent = 19
    TabOrder = 15
    Visible = False
  end
  object P2: TPanel
    Left = 592
    Top = 140
    Width = 377
    Height = 145
    TabOrder = 13
    Visible = False
    DesignSize = (
      377
      145)
    object L1: TLabel
      Left = 16
      Top = 13
      Width = 20
      Height = 21
      Caption = 'L1'
    end
    object Ed1: TEdit
      Left = 16
      Top = 40
      Width = 345
      Height = 29
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 0
      Text = 'Ed1'
    end
    object BitBtn2: TBitBtn
      Left = 24
      Top = 104
      Width = 89
      Height = 25
      Anchors = [akLeft, akBottom]
      Kind = bkOK
      NumGlyphs = 2
      TabOrder = 1
      OnClick = BitBtn2Click
    end
    object BitBtn3: TBitBtn
      Left = 256
      Top = 104
      Width = 91
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = #1054#1090#1084#1077#1085#1072
      Kind = bkNo
      NumGlyphs = 2
      TabOrder = 2
      OnClick = BitBtn3Click
    end
  end
  object P1: TPanel
    Left = 24
    Top = 79
    Width = 369
    Height = 153
    Color = clRed
    ParentBackground = False
    TabOrder = 16
    Visible = False
    object Label1: TLabel
      Left = 128
      Top = 24
      Width = 105
      Height = 21
      Caption = #1042#1099' '#1091#1074#1077#1088#1077#1085#1099'?'
      Color = clBlack
      ParentColor = False
    end
    object BitBtn4: TBitBtn
      Left = 25
      Top = 96
      Width = 97
      Height = 25
      Caption = #1059#1076#1072#1083#1080#1090#1100
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333333333330000333333333333333333333333F33333333333
        00003333344333333333333333388F3333333333000033334224333333333333
        338338F3333333330000333422224333333333333833338F3333333300003342
        222224333333333383333338F3333333000034222A22224333333338F338F333
        8F33333300003222A3A2224333333338F3838F338F33333300003A2A333A2224
        33333338F83338F338F33333000033A33333A222433333338333338F338F3333
        0000333333333A222433333333333338F338F33300003333333333A222433333
        333333338F338F33000033333333333A222433333333333338F338F300003333
        33333333A222433333333333338F338F00003333333333333A22433333333333
        3338F38F000033333333333333A223333333333333338F830000333333333333
        333A333333333333333338330000333333333333333333333333333333333333
        0000}
      ModalResult = 1
      NumGlyphs = 2
      TabOrder = 0
      OnClick = BitBtn4Click
    end
    object BitBtn5: TBitBtn
      Left = 248
      Top = 96
      Width = 97
      Height = 25
      Cancel = True
      Caption = #1054#1090#1084#1077#1085#1072
      Default = True
      Glyph.Data = {
        DE010000424DDE01000000000000760000002800000024000000120000000100
        0400000000006801000000000000000000001000000000000000000000000000
        80000080000000808000800000008000800080800000C0C0C000808080000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333FFFFF333333000033333388888833333333333F888888FFF333
        000033338811111188333333338833FFF388FF33000033381119999111833333
        38F338888F338FF30000339119933331111833338F388333383338F300003391
        13333381111833338F8F3333833F38F3000039118333381119118338F38F3338
        33F8F38F000039183333811193918338F8F333833F838F8F0000391833381119
        33918338F8F33833F8338F8F000039183381119333918338F8F3833F83338F8F
        000039183811193333918338F8F833F83333838F000039118111933339118338
        F3833F83333833830000339111193333391833338F33F8333FF838F300003391
        11833338111833338F338FFFF883F83300003339111888811183333338FF3888
        83FF83330000333399111111993333333388FFFFFF8833330000333333999999
        3333333333338888883333330000333333333333333333333333333333333333
        0000}
      ModalResult = 7
      NumGlyphs = 2
      TabOrder = 1
      OnClick = BitBtn5Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 712
    Top = 1
    object N1: TMenuItem
      Caption = #1060#1072#1081#1083
      object N6: TMenuItem
        Caption = #1053#1086#1074#1099#1081' '#1089#1082#1088#1080#1087#1090
        OnClick = N6Click
      end
      object N2: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
        ShortCut = 16467
        OnClick = N2Click
      end
      object N7: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1082#1072#1082
        OnClick = N7Click
      end
      object N5: TMenuItem
        Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1082#1088#1080#1087#1090
        OnClick = N5Click
      end
    end
    object N3: TMenuItem
      Caption = #1056#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1077
      object N4: TMenuItem
        Caption = #1056#1077#1078#1080#1084' '#1088#1077#1076#1072#1082#1090#1080#1088#1086#1074#1072#1085#1080#1103
        ShortCut = 16453
        OnClick = N4Click
      end
      object N8: TMenuItem
        Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1088#1077#1087#1083#1080#1082#1091' '#1072#1073#1086#1085#1077#1085#1090#1072
        ShortCut = 16449
        OnClick = N8Click
      end
    end
  end
  object PM1: TPopupMenu
    Left = 768
    Top = 8
    object N11: TMenuItem
      Caption = #1044#1074#1080#1085#1091#1090#1100' '#1074#1074#1077#1088#1093
      OnClick = N11Click
    end
    object N10: TMenuItem
      Caption = #1048#1079#1084#1077#1085#1080#1090#1100
      OnClick = N10Click
    end
    object N9: TMenuItem
      Caption = #1059#1076#1072#1083#1080#1090#1100
      OnClick = N9Click
    end
  end
end
