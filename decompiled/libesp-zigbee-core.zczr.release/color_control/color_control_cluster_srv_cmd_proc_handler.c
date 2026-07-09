/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> color_control_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int color_control_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  ushort uVar10;
  undefined1 uVar11;
  ushort uStack_a4;
  ushort uStack_a2;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined2 uStack_8c;
  uint uStack_88;
  undefined1 uStack_84;
  code *pcStack_80;
  undefined4 uStack_7c;
  undefined2 auStack_78 [2];
  uint uStack_74;
  uint uStack_70;
  ushort uStack_6c;
  uint uStack_68;
  char cStack_64;
  code *pcStack_60;
  undefined4 uStack_5c;
  undefined1 auStack_58 [52];
  
  memset(auStack_58,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  iVar3 = color_control_srv_get_attr_desc(*(undefined1 *)(param_1 + 0x15),0x400a);
  if (iVar3 == 0) {
    return 1;
  }
  uVar10 = **(ushort **)(iVar3 + 8);
  if (bVar1 < 0x44) {
    if (bVar1 < 0x40) {
      if (bVar1 < 10) {
        if (6 < bVar1) {
          uVar10 = uVar10 >> 3;
        }
      }
      else {
        if (bVar1 != 10) {
          return 1;
        }
_L0:
        uVar10 = uVar10 >> 4;
      }
    }
    else {
      uVar10 = uVar10 >> 1;
    }
_L0:
    if ((uVar10 & 1) == 0) {
      return 1;
    }
  }
  else if (bVar1 != 0x47) {
    if (0x47 < bVar1) {
      if (1 < (byte)(bVar1 + 0xb5)) {
        return 1;
      }
      goto _L0;
    }
    uVar10 = uVar10 >> 2;
    if (bVar1 != 0x44) {
      return 1;
    }
    goto _L0;
  }
  iVar3 = zcl_packet_init(auStack_58,*(ushort *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  iVar3 = 0;
  if (bVar1 == 10) {
    uStack_a4 = 0;
    uStack_98 = 0;
    uStack_94 = (uint)uStack_94._2_2_ << 0x10;
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a4,&uStack_98);
    af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a4,(int)&uStack_98 + 2);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar4 < uStack_a4) goto _L0;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a4,&uStack_94);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a4,(int)&uStack_94 + 1);
    iVar5 = color_control_check_options_is_exec
                      (*(undefined1 *)(param_1 + 0x15),uStack_94 & 0xff,uStack_94 >> 8 & 0xff);
    if ((iVar5 == 0) || (iVar3 = color_control_change_color_mode(param_1,2), iVar3 != 0)) goto _L0;
    uVar11 = *(undefined1 *)(param_1 + 0x15);
    memset(auStack_78,0,0x18);
    uStack_6c = 1;
    uStack_68 = uStack_98 >> 0x10;
    auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
    pcStack_60 = cvc_color_temperature_output_handler;
    uStack_5c = 7;
    iVar3 = color_control_srv_get_attr_desc(uVar11);
    if (iVar3 == 0) goto _L0;
    color_control_get_color_temperature_range_part_0(uVar11,&uStack_a2,&uStack_a0);
    uStack_74 = (uint)**(ushort **)(iVar3 + 8);
    uStack_70 = uStack_98 & 0xffff;
    if ((uStack_98 & 0xffff) < (uint)uStack_a2) {
      uStack_70 = (uint)uStack_a2;
    }
    if ((uStack_a0 & 0xffff) < uStack_70) {
      uStack_70 = uStack_a0 & 0xffff;
    }
_L0:
    iVar3 = schedule_cvc_color_line(uVar11,auStack_78);
  }
  else if (bVar1 < 0xb) {
    if (bVar1 == 6) {
      uStack_a2 = 0;
      uStack_a0 = 0;
      uStack_9c = (uint)uStack_9c._2_2_ << 0x10;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_a0);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_a0 + 1);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_a0 + 2);
      uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (uVar4 < uStack_a2) goto _L0;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_9c);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_9c + 1);
      iVar5 = color_control_check_options_is_exec
                        (*(undefined1 *)(param_1 + 0x15),uStack_9c & 0xff,uStack_9c >> 8 & 0xff);
      if ((iVar5 != 0) && (iVar3 = color_control_change_color_mode(param_1,0), iVar3 == 0)) {
        uVar11 = *(undefined1 *)(param_1 + 0x15);
        memset(&uStack_98,0,0x20);
        uVar4 = uStack_a0 >> 0x10;
        pcStack_80 = cvc_hue_output_handler;
        uStack_98 = CONCAT31(uStack_98._1_3_,uVar11);
        uStack_8c = 1;
        uStack_88 = uVar4;
        memset(auStack_78,0,0x18);
        pcStack_60 = cvc_sat_output_handler;
        auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
        uStack_6c = 1;
        uStack_5c = 1;
        uStack_68 = uVar4;
        if ((uStack_a0._1_1_ != -1) && ((uStack_a0 & 0xff) != 0xff)) {
          iVar3 = color_control_srv_get_attr_desc(uVar11,0);
          iVar5 = color_control_srv_get_attr_desc(uVar11,1);
          if ((iVar3 != 0) && (iVar5 != 0)) {
            uStack_94 = (uint)**(byte **)(iVar3 + 8);
            uStack_90 = uStack_a0 & 0xff;
            uStack_74 = (uint)**(byte **)(iVar5 + 8);
            uStack_70 = uStack_a0 >> 8 & 0xff;
            goto _L0;
          }
          goto _L0;
        }
_L0:
        uStack_6c = 1;
        iVar3 = 0x87;
      }
    }
    else if (bVar1 < 7) {
      if (bVar1 == 3) {
        uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
        uStack_98 = 0;
        uStack_94 = (uint)uStack_94._2_2_ << 0x10;
        af_read_le8_isra_0(&uStack_a0,&uStack_98);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
        uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar4 < (uStack_a0 & 0xffff)) goto _L0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 1);
        iVar5 = color_control_check_options_is_exec
                          (*(undefined1 *)(param_1 + 0x15),uStack_94 & 0xff,uStack_94 >> 8 & 0xff);
        if ((iVar5 != 0) && (iVar3 = color_control_change_color_mode(param_1,0), iVar3 == 0)) {
          uVar11 = *(undefined1 *)(param_1 + 0x15);
          memset(auStack_78,0,0x18);
          uStack_68 = uStack_98 >> 0x10;
          uStack_6c = 1;
          uStack_5c = 1;
          pcStack_60 = cvc_sat_output_handler;
          auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
          if ((uStack_98 & 0xff) == 0xff) goto _L0;
          iVar3 = color_control_srv_get_attr_desc(uVar11,1);
          if (iVar3 != 0) {
            uStack_74 = (uint)**(byte **)(iVar3 + 8);
            uStack_70 = uStack_98 & 0xff;
            goto _L0;
          }
          goto _L0;
        }
      }
      else {
        if (bVar1 < 4) {
          if (bVar1 != 1) {
            if (bVar1 == 2) goto _L0;
            uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
            uStack_98 = 0;
            uStack_94 = (uint)uStack_94._2_2_ << 0x10;
            af_read_le8_isra_0(&uStack_a0,&uStack_98);
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 1);
            af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
            uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
            if (uVar4 < (uStack_a0 & 0xffff)) goto _L0;
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 1);
            iVar5 = color_control_check_options_is_exec
                              (*(undefined1 *)(param_1 + 0x15),uStack_94 & 0xff,
                               uStack_94 >> 8 & 0xff);
            if ((iVar5 == 0) || (iVar3 = color_control_change_color_mode(param_1,0), iVar3 != 0))
            goto _L0;
            uVar11 = *(undefined1 *)(param_1 + 0x15);
            memset(auStack_78,0,0x20);
            uStack_6c = 1;
            uStack_68 = uStack_98 >> 0x10;
            auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
            pcStack_60 = cvc_hue_output_handler;
            if ((uStack_98 & 0xff) == 0xff) goto _L0;
            iVar3 = color_control_srv_get_attr_desc(uVar11,0);
            if (iVar3 == 0) goto _L0;
            uStack_74 = (uint)**(byte **)(iVar3 + 8);
            uVar4 = uStack_98 & 0xff;
            if (uStack_98._1_1_ == 2) goto _L0;
            if (uStack_98._1_1_ < 3) {
              if (uStack_98._1_1_ == 0) {
                iVar3 = uStack_74 - uVar4;
                if (uStack_74 <= uVar4) {
                  iVar3 = uVar4 - uStack_74;
                }
                if (uStack_74 < uVar4 == 0x7f < iVar3) goto _L0;
              }
              else {
                iVar3 = uStack_74 - uVar4;
                if (uStack_74 <= uVar4) {
                  iVar3 = uVar4 - uStack_74;
                }
                if (uStack_74 < uVar4 != 0x7f < iVar3) goto _L0;
              }
_L0:
              uStack_70 = uVar4;
              if (uVar4 < uStack_74) {
                uStack_70 = uVar4 + 0xff;
              }
            }
            else {
              if (uStack_98._1_1_ != 3) goto _L0;
_L0:
              uStack_70 = uVar4;
              if (uStack_74 < uVar4) {
                uStack_70 = uVar4 - 0xff;
              }
            }
            goto _L0;
          }
        }
        else if (bVar1 != 4) {
_L0:
          uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
          uStack_98 = 0;
          uStack_94 = uStack_94 & 0xffff0000;
          af_read_le8_isra_0(&uStack_a0,&uStack_98);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 1);
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
          uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          if (uVar4 < (uStack_a0 & 0xffff)) goto _L0;
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 1);
          iVar5 = color_control_check_options_is_exec
                            (*(undefined1 *)(param_1 + 0x15),uStack_94 & 0xff,uStack_94 >> 8 & 0xff)
          ;
          if ((iVar5 == 0) || (iVar3 = color_control_change_color_mode(param_1,0), iVar3 != 0))
          goto _L0;
          uVar11 = *(undefined1 *)(param_1 + 0x15);
          uStack_68 = uStack_98 >> 0x10;
          auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
          uStack_74 = 0;
          uStack_70 = 0;
          uStack_6c = 1;
          cStack_64 = '\0';
          if (*(char *)(param_1 + 0x20) != '\x02') {
            pcStack_60 = cvc_sat_output_handler;
            uStack_5c = 1;
            iVar3 = color_control_srv_get_attr_desc(uVar11,1);
            if (iVar3 != 0) {
              uStack_74 = (uint)**(byte **)(iVar3 + 8);
              if ((uStack_98 & 0xff) == 1) {
                uStack_70 = uStack_74 + uStack_98._1_1_;
                if (0xfe < uStack_74 + uStack_98._1_1_) {
                  uStack_70 = 0xfe;
                }
              }
              else {
                if ((uStack_98 & 0xff) != 3) goto _L0;
                uStack_70 = uStack_74 - uStack_98._1_1_ &
                            (int)~(uStack_74 - uStack_98._1_1_) >> 0x1f;
              }
              goto _L0;
            }
_L0:
            iVar3 = 0x86;
            goto _L0;
          }
          pcStack_60 = cvc_hue_output_handler;
          uStack_5c = 0;
          iVar3 = color_control_srv_get_attr_desc(uVar11,0);
          if (iVar3 == 0) goto _L0;
          uStack_74 = (uint)**(byte **)(iVar3 + 8);
          if ((uStack_98 & 0xff) == 1) {
            uStack_70 = uStack_74 + uStack_98._1_1_;
_L0:
            iVar3 = 0;
          }
          else {
            if ((uStack_98 & 0xff) == 3) {
              uStack_70 = uStack_74 - uStack_98._1_1_;
              goto _L0;
            }
_L0:
            iVar3 = 0x85;
          }
          uVar4 = uStack_98 >> 0x10;
          goto _L0;
        }
        uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
        uStack_98 = 0;
        af_read_le8_isra_0(&uStack_a0,&uStack_98);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 1);
        uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        iVar3 = 0x80;
        if ((uStack_a0 & 0xffff) <= uVar4) {
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 3);
          iVar3 = color_control_check_options_is_exec
                            (*(undefined1 *)(param_1 + 0x15),uStack_98 >> 0x10 & 0xff,
                             uStack_98 >> 0x18);
          if (iVar3 == 0) goto _L0;
          iVar3 = color_control_change_color_mode(param_1,0);
          if (iVar3 == 0) {
            uVar11 = *(undefined1 *)(param_1 + 0x15);
            cStack_64 = *(char *)(param_1 + 0x20);
            auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
            uStack_74 = 0;
            uStack_70 = 0;
            if (cStack_64 == '\x01') {
              uStack_68 = 10;
              uStack_6c = 1;
              pcStack_60 = cvc_hue_output_handler;
              uStack_5c = 0;
              iVar3 = color_control_srv_get_attr_desc(uVar11,0);
              if (iVar3 != 0) {
                uVar4 = uStack_98 & 0xff;
                uStack_74 = (uint)**(byte **)(iVar3 + 8);
                if (uVar4 == 1) {
                  uVar4 = (uint)uStack_98._1_1_;
                  goto _L0;
                }
                if (uVar4 == 3) {
                  uVar4 = (uint)uStack_98._1_1_;
_L0:
                  if (uVar4 != 0) {
                    uVar2 = uStack_74 - uVar4;
                    goto _L0;
                  }
                }
                else {
joined_r0x0001278c:
                  if (uVar4 == 0) {
                    uVar9 = 0;
                    goto _L0;
                  }
                }
                goto _L0;
              }
            }
            else {
              uStack_6c = 1;
              uStack_68 = 0;
              cStack_64 = '\0';
              pcStack_60 = cvc_sat_output_handler;
              uStack_5c = 1;
              iVar3 = color_control_srv_get_attr_desc(uVar11,1,0);
              if (iVar3 != 0) {
                uStack_74 = (uint)**(byte **)(iVar3 + 8);
                uVar4 = uStack_98 & 0xff;
                if (uVar4 == 1) {
                  if (uStack_98._1_1_ != 0) {
                    uStack_68 = (int)(((uint)uStack_6c * 0xa0000 >> 0x10) * (0xfe - uStack_74)) /
                                (int)(uint)uStack_98._1_1_;
                    uVar2 = 0xfe;
_L0:
                    uStack_70 = uVar2;
                    iVar3 = schedule_cvc_color_line(uVar11,auStack_78);
                    goto _L0;
                  }
                }
                else {
                  if (uVar4 != 3) goto joined_r0x0001278c;
                  if (uStack_98._1_1_ != 0) {
                    uStack_68 = (((uint)uStack_6c * 0xa0000 >> 0x10) * uStack_74) /
                                (uint)uStack_98._1_1_;
                    uVar2 = 0;
                    goto _L0;
                  }
                }
_L0:
                iVar3 = 0x85;
                goto _L0;
              }
            }
_L0:
            iVar3 = 0x86;
          }
        }
      }
    }
    else if (bVar1 == 8) {
      uStack_a2 = 0;
      uStack_a0 = 0;
      uStack_9c = (uint)uStack_9c._2_2_ << 0x10;
      af_read_le16_isra_0(&uStack_a2,&uStack_a0);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_a0 + 2);
      uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (uVar4 < uStack_a2) goto _L0;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_9c);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_9c + 1);
      iVar5 = color_control_check_options_is_exec
                        (*(undefined1 *)(param_1 + 0x15),uStack_9c & 0xff,uStack_9c >> 8 & 0xff);
      if ((iVar5 != 0) && (iVar3 = color_control_change_color_mode(param_1,1), iVar3 == 0)) {
        pcStack_80 = cvc_color_xy_output_handler;
        pcStack_60 = cvc_color_xy_output_handler;
        uVar11 = *(undefined1 *)(param_1 + 0x15);
        uStack_8c = 1;
        uStack_84 = 1;
        uStack_6c = 1;
        cStack_64 = '\x01';
        uStack_5c = 4;
        uStack_98 = CONCAT31(uStack_98._1_3_,uVar11);
        uStack_94 = 0;
        uStack_90 = 0;
        uStack_88 = 0;
        uStack_7c = 3;
        auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
        uStack_74 = 0;
        uStack_70 = 0;
        uStack_68 = 0;
        if ((ushort)uStack_a0 != 0 || uStack_a0._2_2_ != 0) {
          iVar3 = color_control_srv_get_attr_desc(uVar11,3);
          iVar5 = color_control_srv_get_attr_desc(uVar11,4);
          if ((iVar3 != 0) && (iVar5 != 0)) {
            uStack_94 = (uint)**(ushort **)(iVar3 + 8);
            uStack_74 = (uint)**(ushort **)(iVar5 + 8);
            uStack_90 = uStack_94 + (uStack_a0 & 0xffff);
            uStack_70 = uStack_74 + (uStack_a0 >> 0x10);
            uStack_88 = (-(uint)((uStack_a0 & 0xffff) == 0) & 0xfffffff6) + 10;
            uStack_68 = (-(uint)(uStack_a0 >> 0x10 == 0) & 0xfffffff6) + 10;
            goto _L0;
          }
          goto _L0;
        }
        stop_cvc_color(uVar11,1);
        iVar3 = 0xfe;
      }
    }
    else if (bVar1 == 9) {
      uStack_a2 = 0;
      uStack_a0 = 0;
      uStack_9c = uStack_9c & 0xffff0000;
      af_read_le16_isra_0(&uStack_a2,&uStack_a0);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_a0 + 1);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_a0 + 2);
      uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (uVar4 < uStack_a2) goto _L0;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_9c);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_9c + 1);
      iVar5 = color_control_check_options_is_exec
                        (*(undefined1 *)(param_1 + 0x15),uStack_9c & 0xff,uStack_9c >> 8 & 0xff);
      if ((iVar5 != 0) && (iVar3 = color_control_change_color_mode(param_1,1), iVar3 == 0)) {
        uVar11 = *(undefined1 *)(param_1 + 0x15);
        uStack_88 = uStack_a0 >> 0x10;
        uStack_7c = 3;
        uStack_98 = CONCAT31(uStack_98._1_3_,uVar11);
        uStack_94 = 0;
        uStack_90 = 0;
        uStack_8c = 1;
        uStack_84 = 0;
        pcStack_80 = cvc_color_xy_output_handler;
        auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
        uStack_74 = 0;
        uStack_70 = 0;
        uStack_6c = 1;
        cStack_64 = '\0';
        pcStack_60 = cvc_color_xy_output_handler;
        uStack_5c = 4;
        uStack_68 = uStack_88;
        iVar3 = color_control_srv_get_attr_desc(uVar11);
        iVar5 = color_control_srv_get_attr_desc(uVar11,4);
        if ((iVar3 == 0) || (iVar5 == 0)) goto _L0;
        uStack_94 = (uint)**(ushort **)(iVar3 + 8);
        uStack_74 = (uint)**(ushort **)(iVar5 + 8);
        uStack_90 = (uStack_a0 & 0xff) + uStack_94;
        uStack_70 = (uStack_a0 >> 8 & 0xff) + uStack_74;
        color_control_set_remaining_time(uVar11,uStack_a0 >> 0x10);
_L0:
        iVar3 = schedule_cvc_color_space(uVar11,&uStack_98,auStack_78);
      }
    }
    else {
      uStack_a2 = 0;
      uStack_a0 = 0;
      uStack_9c = 0;
      af_read_le16_isra_0(&uStack_a2,&uStack_a0);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_a0 + 2);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_9c);
      uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (uVar4 < uStack_a2) {
_L0:
        iVar3 = 0x80;
      }
      else {
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_9c + 2);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_9c + 3);
        iVar5 = color_control_check_options_is_exec
                          (*(undefined1 *)(param_1 + 0x15),uStack_9c >> 0x10 & 0xff,
                           uStack_9c >> 0x18);
        if (iVar5 != 0) {
          iVar3 = color_control_change_color_mode(param_1,1);
          if (iVar3 == 0) {
            uVar11 = *(undefined1 *)(param_1 + 0x15);
            memset(&uStack_98,0,0x18);
            uVar4 = uStack_9c & 0xffff;
            uStack_98 = CONCAT31(uStack_98._1_3_,uVar11);
            uStack_8c = 1;
            pcStack_80 = cvc_color_xy_output_handler;
            uStack_7c = 3;
            uStack_88 = uVar4;
            memset(auStack_78,0,0x18);
            auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
            uStack_6c = 1;
            pcStack_60 = cvc_color_xy_output_handler;
            uStack_5c = 4;
            uStack_68 = uVar4;
            if ((0xfeff < (ushort)uStack_a0) || (0xfeff < uStack_a0 >> 0x10)) goto _L0;
            iVar3 = color_control_srv_get_attr_desc(uVar11,3);
            iVar5 = color_control_srv_get_attr_desc(uVar11,4);
            if ((iVar3 != 0) && (iVar5 != 0)) {
              uVar10 = **(ushort **)(iVar3 + 8);
              uStack_74 = (uint)**(ushort **)(iVar5 + 8);
              uStack_70 = uStack_a0 >> 0x10;
              goto _L0;
            }
            goto _L0;
          }
          if (iVar3 == 0xfe) goto _L0;
        }
      }
    }
  }
  else {
    if (bVar1 == 0x44) {
      uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
      uStack_98 = 0;
      uStack_94 = 0;
      uStack_90 = (uint)uStack_90._2_2_ << 0x10;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_98);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 1);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
      af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 2);
      uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      iVar3 = 0x80;
      if (uVar4 < (uStack_a0 & 0xffff)) goto _L0;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_90);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_90 + 1);
      iVar3 = color_control_check_options_is_exec
                        (*(undefined1 *)(param_1 + 0x15),uStack_90 & 0xff,uStack_90 >> 8 & 0xff);
      if (iVar3 == 0) goto _L0;
      iVar3 = color_control_change_color_mode(param_1,3);
      if (iVar3 != 0) goto _L0;
      uVar11 = *(undefined1 *)(param_1 + 0x15);
      uStack_6c = 1;
      pcStack_60 = cvc_enhanced_hue_output_handler;
      uStack_5c = 0x4000;
      auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
      uStack_74 = 0;
      uStack_70 = 0;
      uStack_68 = 0;
      cStack_64 = '\0';
      iVar5 = color_control_srv_get_attr_desc(uVar11,0x4002,0);
      iVar6 = color_control_srv_get_attr_desc(uVar11,0x4003);
      iVar7 = color_control_srv_get_attr_desc(uVar11,0x4004);
      iVar3 = color_control_srv_get_attr_desc(uVar11,0x4005);
      iVar8 = color_control_srv_get_attr_desc(uVar11,0x4000);
      if ((((iVar5 == 0) || (iVar6 == 0)) || (iVar7 == 0)) || ((iVar3 == 0 || (iVar8 == 0))))
      goto _L0;
      if ((uStack_98 & 2) != 0) {
        **(undefined1 **)(iVar6 + 8) = uStack_98._2_1_;
      }
      if ((uStack_98 & 4) != 0) {
        **(undefined2 **)(iVar7 + 8) = (undefined2)uStack_94;
      }
      if ((uStack_98 & 8) != 0) {
        **(undefined2 **)(iVar3 + 8) = uStack_94._2_2_;
      }
      if ((uStack_98 & 1) != 0) {
        if (uStack_98._1_1_ == '\x01') {
          color_control_copy_attr_u16(uVar11,0x4000,0x4005);
          **(undefined1 **)(iVar5 + 8) = 1;
        }
        else if (uStack_98._1_1_ == '\x02') {
          color_control_copy_attr_u16(uVar11,0x4000,0x4006);
          **(undefined1 **)(iVar5 + 8) = 1;
        }
        else {
          iVar3 = 0x87;
          if (uStack_98._1_1_ != '\0') goto _L0;
          if (**(char **)(iVar5 + 8) == '\x01') {
            **(char **)(iVar5 + 8) = '\0';
            color_control_copy_attr_u16(uVar11,0x4006);
          }
        }
      }
      if (**(char **)(iVar5 + 8) != '\0') {
        uStack_68 = (uint)**(ushort **)(iVar7 + 8) * 10;
        uStack_74 = (uint)**(ushort **)(iVar8 + 8);
        if (**(char **)(iVar6 + 8) == '\0') {
          iVar3 = 0x10000;
        }
        else {
          iVar3 = -0x10000;
        }
        uStack_70 = uStack_74 + iVar3;
        schedule_cvc_color_line(uVar11,auStack_78);
        goto _L0;
      }
      uVar9 = 3;
_L0:
      stop_cvc_color(uVar11,uVar9);
    }
    else {
      if (bVar1 < 0x45) {
        if (bVar1 == 0x42) {
          uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
          uStack_98 = 0;
          uStack_94 = 0;
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_98);
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 2);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 3);
          iVar5 = color_control_check_options_is_exec
                            (*(undefined1 *)(param_1 + 0x15),uStack_94 >> 0x10 & 0xff,
                             uStack_94 >> 0x18);
          if ((iVar5 == 0) || (iVar3 = color_control_change_color_mode(param_1,3), iVar3 != 0))
          goto _L0;
          uStack_68 = uStack_94 & 0xffff;
          uVar11 = *(undefined1 *)(param_1 + 0x15);
          auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
          uStack_74 = 0;
          uStack_70 = 0;
          uStack_6c = 1;
          cStack_64 = '\0';
          pcStack_60 = cvc_enhanced_hue_output_handler;
          uStack_5c = 0x4000;
          iVar3 = color_control_srv_get_attr_desc(uVar11);
          if (iVar3 == 0) goto _L0;
          uStack_74 = (uint)**(ushort **)(iVar3 + 8);
          if ((uStack_98 & 0xff) == 1) {
            uStack_70 = (uint)uStack_98._2_2_;
_L0:
            uStack_70 = uStack_74 + uStack_70;
            iVar3 = 0;
          }
          else {
            if ((uStack_98 & 0xff) == 3) {
              uStack_70 = -(uint)uStack_98._2_2_;
              goto _L0;
            }
            iVar3 = 0x85;
          }
          uVar4 = uStack_94 & 0xffff;
_L0:
          color_control_set_remaining_time(uVar11,uVar4);
          if (iVar3 == 0) goto _L0;
        }
        else {
          if (bVar1 == 0x43) {
            uStack_a2 = 0;
            uStack_a0 = 0;
            uStack_9c = 0;
            af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_a0);
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_a0 + 2);
            af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_9c);
            uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
            if (uVar4 < uStack_a2) goto _L0;
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_9c + 2);
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_9c + 3);
            iVar5 = color_control_check_options_is_exec
                              (*(undefined1 *)(param_1 + 0x15),uStack_9c >> 0x10 & 0xff,
                               uStack_9c >> 0x18);
            if ((iVar5 != 0) && (iVar3 = color_control_change_color_mode(param_1,3), iVar3 == 0)) {
              uVar11 = *(undefined1 *)(param_1 + 0x15);
              memset(&uStack_98,0,0x18);
              uVar4 = uStack_9c & 0xffff;
              pcStack_80 = cvc_enhanced_hue_output_handler;
              uStack_98 = CONCAT31(uStack_98._1_3_,uVar11);
              uStack_8c = 1;
              uStack_7c = 0x4000;
              uStack_88 = uVar4;
              memset(auStack_78,0,0x18);
              pcStack_60 = cvc_sat_output_handler;
              auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
              uStack_6c = 1;
              uStack_5c = 1;
              uStack_68 = uVar4;
              if ((uStack_a0 >> 0x10 & 0xff) == 0xff) goto _L0;
              iVar3 = color_control_srv_get_attr_desc(uVar11,0x4000);
              iVar5 = color_control_srv_get_attr_desc(uVar11,1);
              if ((iVar3 != 0) && (iVar5 != 0)) {
                uVar10 = **(ushort **)(iVar3 + 8);
                uStack_74 = (uint)**(byte **)(iVar5 + 8);
                uStack_70 = uStack_a0 >> 0x10 & 0xff;
_L0:
                uStack_90 = uStack_a0 & 0xffff;
                uStack_94 = (uint)uVar10;
                goto _L0;
              }
              goto _L0;
            }
            goto _L0;
          }
          if (bVar1 != 0x40) {
            if (bVar1 != 0x41) goto _L0;
            uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
            uStack_98 = 0;
            uStack_94 = (uint)uStack_94._2_2_ << 0x10;
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_98);
            af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
            uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
            iVar3 = 0x80;
            if (uVar4 < (uStack_a0 & 0xffff)) goto _L0;
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
            af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 1);
            iVar3 = color_control_check_options_is_exec
                              (*(undefined1 *)(param_1 + 0x15),uStack_94 & 0xff,
                               uStack_94 >> 8 & 0xff);
            if (iVar3 == 0) goto _L0;
            iVar3 = color_control_change_color_mode(param_1,3);
            if (iVar3 != 0) goto _L0;
            uVar11 = *(undefined1 *)(param_1 + 0x15);
            uStack_68 = 10;
            auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
            uStack_74 = 0;
            uStack_70 = 0;
            uStack_6c = 1;
            cStack_64 = '\x01';
            pcStack_60 = cvc_enhanced_hue_output_handler;
            uStack_5c = 0x4000;
            iVar3 = color_control_srv_get_attr_desc(uVar11,0);
            if (iVar3 == 0) goto _L0;
            uVar4 = uStack_98 & 0xff;
            uStack_74 = (uint)**(ushort **)(iVar3 + 8);
            if (uVar4 != 1) {
              uVar9 = 3;
              if (uVar4 != 3) {
                if (uVar4 != 0) goto _L0;
                goto _L0;
              }
              uVar4 = (uint)uStack_98._2_2_;
              goto _L0;
            }
            uVar4 = (uint)uStack_98._2_2_;
_L0:
            uVar2 = uStack_74 + uVar4;
            if (uVar4 != 0) goto _L0;
            goto _L0;
          }
          uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
          uStack_98 = 0;
          uStack_94 = 0;
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_98);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
          af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
          uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          if (uVar4 < (uStack_a0 & 0xffff)) goto _L0;
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 2);
          af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 3);
          iVar5 = color_control_check_options_is_exec
                            (*(undefined1 *)(param_1 + 0x15),uStack_94 >> 0x10 & 0xff,
                             uStack_94 >> 0x18);
          if ((iVar5 == 0) || (iVar3 = color_control_change_color_mode(param_1,3), iVar3 != 0))
          goto _L0;
          uVar11 = *(undefined1 *)(param_1 + 0x15);
          memset(auStack_78,0,0x18);
          uStack_6c = 1;
          uStack_68 = uStack_94 & 0xffff;
          auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
          pcStack_60 = cvc_enhanced_hue_output_handler;
          uStack_5c = 0x4000;
          iVar3 = color_control_srv_get_attr_desc(uVar11);
          if (iVar3 == 0) goto _L0;
          uStack_74 = (uint)**(ushort **)(iVar3 + 8);
          uVar4 = uStack_98 & 0xffff;
          if (uStack_98._2_1_ == 2) {
_L0:
            uStack_70 = uVar4;
            if (uStack_74 <= uVar4) goto _L0;
            iVar3 = 0x10000;
_L0:
            uStack_70 = uVar4 + iVar3;
            goto _L0;
          }
          if (uStack_98._2_1_ < 3) {
            if (uStack_98._2_1_ == 0) {
              iVar3 = uStack_74 - uVar4;
              if (uStack_74 <= uVar4) {
                iVar3 = uVar4 - uStack_74;
              }
            }
            else {
              iVar3 = uStack_74 - uVar4;
              if (uStack_74 <= uVar4) {
                iVar3 = uVar4 - uStack_74;
              }
            }
            if (uStack_74 < uVar4 == 0x8000 < iVar3) goto _L0;
_L0:
            uStack_70 = uVar4;
            if (uVar4 <= uStack_74) goto _L0;
            iVar3 = -0x10000;
            goto _L0;
          }
          if (uStack_98._2_1_ == 3) goto _L0;
        }
_L0:
        iVar3 = 0x85;
        goto _L0;
      }
      if (bVar1 == 0x4b) {
        uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
        uStack_98 = 0;
        uStack_94 = 0;
        uStack_90 = (uint)uStack_90._2_2_ << 0x10;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_98);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 2);
        uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        iVar3 = 0x80;
        if (uVar4 < (uStack_a0 & 0xffff)) goto _L0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_90);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_90 + 1);
        iVar3 = color_control_check_options_is_exec
                          (*(undefined1 *)(param_1 + 0x15),uStack_90 & 0xff,uStack_90 >> 8 & 0xff);
        if (iVar3 == 0) goto _L0;
        iVar3 = color_control_change_color_mode(param_1,2);
        if (iVar3 != 0) goto _L0;
        uVar11 = *(undefined1 *)(param_1 + 0x15);
        uStack_6c = 1;
        auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
        uStack_74 = 0;
        uStack_70 = 0;
        uStack_68 = 0;
        cStack_64 = '\0';
        pcStack_60 = cvc_color_temperature_output_handler;
        uStack_5c = 7;
        iVar3 = color_control_srv_get_attr_desc(uVar11,0);
        if (iVar3 != 0) {
          uStack_74 = (uint)**(ushort **)(iVar3 + 8);
          uVar4 = uStack_98 & 0xff;
          if (uVar4 == 1) {
            if (uStack_98._2_2_ == 0) goto _L0;
            iVar3 = color_control_srv_get_attr_desc(uVar11,0x400c);
            if (iVar3 != 0) {
              uStack_70 = uStack_94 >> 0x10;
              if (uStack_70 == 0) {
                uStack_70 = (uint)**(ushort **)(iVar3 + 8);
              }
              if ((int)uStack_74 < (int)uStack_70) {
                iVar3 = ((uint)uStack_6c * 0xa0000 >> 0x10) * (uStack_70 - uStack_74);
                goto _L0;
              }
_L0:
              iVar3 = 0x87;
              goto _L0;
            }
            goto _L0;
          }
          if (uVar4 == 3) {
            if (uStack_98._2_2_ == 0) goto _L0;
            iVar3 = color_control_srv_get_attr_desc(uVar11,0x400b);
            if (iVar3 == 0) goto _L0;
            uStack_70 = uStack_94 & 0xffff;
            if (uStack_70 == 0) {
              uStack_70 = (uint)**(ushort **)(iVar3 + 8);
            }
            if ((int)uStack_74 <= (int)uStack_70) goto _L0;
            iVar3 = ((uint)uStack_6c * 0xa0000 >> 0x10) * (uStack_74 - uStack_70);
_L0:
            uStack_68 = iVar3 / (int)(uStack_98 >> 0x10);
            uVar2 = uStack_70;
            goto _L0;
          }
          uVar9 = 2;
          if (uVar4 == 0) goto _L0;
          goto _L0;
        }
        goto _L0;
      }
      if (bVar1 == 0x4c) {
        uStack_a0 = (uint)uStack_a0._2_2_ << 0x10;
        uStack_98 = 0;
        uStack_94 = 0;
        uStack_90 = 0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_98);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_98 + 2);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_90);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,&uStack_94);
        af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_94 + 2);
        uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar4 < (uStack_a0 & 0xffff)) goto _L0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_90 + 2);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_a0,(int)&uStack_90 + 3);
        iVar5 = color_control_check_options_is_exec
                          (*(undefined1 *)(param_1 + 0x15),uStack_90 >> 0x10 & 0xff,
                           uStack_90 >> 0x18);
        if ((iVar5 == 0) || (iVar3 = color_control_change_color_mode(param_1,2), iVar3 != 0))
        goto _L0;
        uStack_68 = uStack_90 & 0xffff;
        uVar11 = *(undefined1 *)(param_1 + 0x15);
        auStack_78[0] = CONCAT11(auStack_78[0]._1_1_,uVar11);
        uStack_74 = 0;
        uStack_70 = 0;
        uStack_6c = 1;
        cStack_64 = '\0';
        pcStack_60 = cvc_color_temperature_output_handler;
        uStack_5c = 7;
        iVar3 = color_control_srv_get_attr_desc(uVar11);
        if (iVar3 != 0) {
          uStack_74 = (uint)**(ushort **)(iVar3 + 8);
          if ((uStack_98 & 0xff) == 1) {
            iVar3 = color_control_srv_get_attr_desc(uVar11,0x400c);
            if (iVar3 != 0) {
              uVar4 = uStack_94 >> 0x10;
              if (uVar4 == 0) {
                uVar4 = (uint)**(ushort **)(iVar3 + 8);
              }
              uStack_70 = (uStack_98 >> 0x10) + uStack_74;
              if ((int)uVar4 < (int)uStack_70) {
_L0:
                uStack_70 = uVar4;
              }
_L0:
              iVar3 = 0;
              goto _L0;
            }
          }
          else {
            if ((uStack_98 & 0xff) != 3) {
              iVar3 = 0x85;
_L0:
              uVar4 = uStack_90 & 0xffff;
              goto _L0;
            }
            iVar3 = color_control_srv_get_attr_desc(uVar11,0x400b);
            if (iVar3 != 0) {
              uVar4 = uStack_94 & 0xffff;
              if (uVar4 == 0) {
                uVar4 = (uint)**(ushort **)(iVar3 + 8);
              }
              uStack_70 = uStack_74 - (uStack_98 >> 0x10);
              if ((int)uStack_70 < (int)uVar4) goto _L0;
              goto _L0;
            }
          }
        }
        goto _L0;
      }
      if (bVar1 != 0x47) {
_L0:
        iVar3 = 0x81;
        goto _L0;
      }
      auStack_78[0] = 0;
      uStack_98 = uStack_98 & 0xffff0000;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_78,&uStack_98);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),auStack_78,(int)&uStack_98 + 1);
      iVar3 = color_control_check_options_is_exec
                        (*(undefined1 *)(param_1 + 0x15),uStack_98 & 0xff,uStack_98 >> 8 & 0xff);
      if (iVar3 != 0) {
        uVar11 = *(undefined1 *)(param_1 + 0x15);
        uVar9 = 0xff;
        goto _L0;
      }
    }
_L0:
    iVar3 = 0;
  }
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_58,param_1,iVar3);
  if (iVar3 == 0) {
    zcl_packet_send(auStack_58,0);
    return 0;
  }
_L0:
  zcl_packet_free(auStack_58);
  return iVar3;
}

