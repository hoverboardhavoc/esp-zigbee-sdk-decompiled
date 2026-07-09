/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> level_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int level_cluster_srv_cmd_proc_handler(int param_1)

{
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ushort uStack_72;
  undefined4 uStack_70;
  undefined2 uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  uint uStack_60;
  undefined2 uStack_5c;
  uint uStack_58;
  undefined1 uStack_54;
  code *pcStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [40];
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar4 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar4 != 0) {
    return iVar4;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  iVar4 = 0;
  if (bVar1 == 4) {
_L0:
    uVar3 = *(undefined1 *)(param_1 + 0x15);
    uStack_72 = 0;
    uStack_70 = 0;
    uStack_6c = 0;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_70);
    uVar9 = (uint)uStack_72;
    iVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar9,2,(int)&uStack_70 + 2);
    if (iVar5 == 0) {
      uVar9 = 0xffff;
    }
    else {
      uVar9 = uVar9 + iVar5 & 0xffff;
    }
    uStack_72 = (ushort)uVar9;
    uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar6 < uVar9) {
_L0:
      iVar4 = 0x80;
      goto _L0;
    }
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_6c);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_6c + 1);
    iVar5 = level_check_options_is_exec(uVar3,bVar1,(undefined1)uStack_6c,uStack_6c._1_1_);
    if (iVar5 == 0) goto _L0;
    cVar2 = *(char *)(param_1 + 0x20);
    uStack_68 = CONCAT31(uStack_68._1_3_,uVar3);
    iVar4 = level_srv_get_attr_desc(uVar3,0);
    uStack_64 = (uint)**(byte **)(iVar4 + 8);
    uStack_54 = 0;
    uStack_60 = uStack_70 & 0xff;
    uStack_5c = 1;
    uStack_58 = uStack_70 >> 0x10;
    if (cVar2 == '\0') {
      pcStack_50 = level_cvc_output_handler;
    }
    else {
      pcStack_50 = level_cvc_with_on_off_output_handler;
    }
    uStack_4c = 0;
    iVar4 = level_srv_get_attr_desc(uVar3,2);
    iVar5 = level_srv_get_attr_desc(uVar3,3);
    uVar9 = 0;
    if (iVar4 != 0) {
      uVar9 = (uint)**(byte **)(iVar4 + 8);
    }
    uVar6 = 0xff;
    if (iVar5 != 0) {
      uVar6 = (uint)**(byte **)(iVar5 + 8);
    }
    uStack_60 = uStack_70 & 0xff;
    if ((int)uStack_64 < (int)uStack_60) {
      if (uVar6 < uStack_60) {
        uStack_60 = uVar6;
      }
    }
    else if (uStack_60 < uVar9) {
      uStack_60 = uVar9;
    }
    uVar9 = uStack_70 >> 0x10;
    if ((uVar9 == 0xffff) && (iVar4 = level_srv_get_attr_desc(uVar3,0x10), iVar4 != 0)) {
      uVar9 = (uint)**(ushort **)(iVar4 + 8);
    }
_L0:
    uStack_58 = uVar9;
    iVar4 = schedule_cvc_level(uVar3,&uStack_68);
  }
  else {
    if (bVar1 < 5) {
      if (bVar1 == 2) {
_L0:
        uVar3 = *(undefined1 *)(param_1 + 0x15);
        uStack_72 = 0;
        uStack_70 = 0;
        uStack_6c = 0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_70);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_70 + 1);
        uVar9 = (uint)uStack_72;
        iVar5 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar9,2,(int)&uStack_70 + 2);
        if (iVar5 == 0) {
          uVar9 = 0xffff;
        }
        else {
          uVar9 = uVar9 + iVar5 & 0xffff;
        }
        uStack_72 = (ushort)uVar9;
        uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uVar6 < uVar9) goto _L0;
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_6c);
        af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_6c + 1);
        iVar5 = level_check_options_is_exec(uVar3,bVar1,(undefined1)uStack_6c,uStack_6c._1_1_);
        if (iVar5 == 0) goto _L0;
        cVar2 = *(char *)(param_1 + 0x20);
        iVar4 = level_srv_get_attr_desc(uVar3,0);
        iVar5 = level_srv_get_attr_desc(uVar3,2);
        iVar7 = level_srv_get_attr_desc(uVar3,3);
        uVar9 = 0;
        if (iVar5 != 0) {
          uVar9 = (uint)**(byte **)(iVar5 + 8);
        }
        uVar6 = 0xff;
        if (iVar7 != 0) {
          uVar6 = (uint)**(byte **)(iVar7 + 8);
        }
        uStack_58 = uStack_70 >> 0x10;
        uStack_64 = (uint)**(byte **)(iVar4 + 8);
        uStack_68 = CONCAT31(uStack_68._1_3_,uVar3);
        if (cVar2 == '\x02') {
          pcStack_50 = level_cvc_output_handler;
        }
        else {
          pcStack_50 = level_cvc_with_on_off_output_handler;
        }
        uVar8 = uStack_70 >> 8 & 0xff;
        if ((char)uStack_70 == '\0') {
          uStack_60 = uVar8 + uStack_64;
          if ((uVar6 <= uVar8 + uStack_64) && (uStack_60 = uVar6, uVar8 != 0)) {
            uStack_58 = ((uVar6 - uStack_64) * uStack_58) / uVar8;
          }
        }
        else {
          uStack_60 = uStack_64 - uVar8;
          if (((int)(uStack_64 - uVar8) <= (int)uVar9) && (uStack_60 = uVar9, uVar8 != 0)) {
            uStack_58 = ((uStack_64 - uVar9) * uStack_58) / uVar8;
          }
        }
        goto _L0;
      }
      if (bVar1 != 3) {
        if (bVar1 != 0) goto _L0;
        goto _L0;
      }
    }
    else if (bVar1 != 7) {
      if (7 < bVar1) {
        if (bVar1 == 8) {
          uStack_68 = uStack_68 & 0xffff0000;
          uVar9 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,2,&uStack_68);
          if (uVar9 == 0) {
            uVar9 = 0xffff;
          }
          uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          iVar4 = (uVar9 <= uVar6) + 0x80;
        }
        else {
          iVar4 = 0x81;
        }
        goto _L0;
      }
      if (bVar1 != 5) goto _L0;
_L0:
      uVar3 = *(undefined1 *)(param_1 + 0x15);
      uStack_72 = 0;
      uStack_70 = 0;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,&uStack_70);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_70 + 1);
      uVar9 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      if (uVar9 < uStack_72) goto _L0;
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_70 + 2);
      af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_72,(int)&uStack_70 + 3);
      iVar5 = level_check_options_is_exec(uVar3,bVar1,uStack_70 >> 0x10 & 0xff,uStack_70 >> 0x18);
      if (iVar5 == 0) goto _L0;
      cVar2 = *(char *)(param_1 + 0x20);
      iVar4 = level_srv_get_attr_desc(uVar3,2);
      iVar5 = level_srv_get_attr_desc(uVar3,3);
      iVar7 = level_srv_get_attr_desc(uVar3,0x14);
      uStack_60 = 0;
      if (iVar4 != 0) {
        uStack_60 = (uint)**(byte **)(iVar4 + 8);
      }
      uVar9 = 0xff;
      if (iVar5 != 0) {
        uVar9 = (uint)**(byte **)(iVar5 + 8);
      }
      uStack_68 = CONCAT31(uStack_68._1_3_,uVar3);
      iVar4 = level_srv_get_attr_desc(uVar3,0);
      uStack_64 = (uint)**(byte **)(iVar4 + 8);
      if ((char)uStack_70 == '\0') {
        uStack_60 = uVar9;
      }
      if (cVar2 == '\x01') {
        pcStack_50 = level_cvc_output_handler;
      }
      else {
        pcStack_50 = level_cvc_with_on_off_output_handler;
      }
      uStack_58 = uStack_70 >> 8 & 0xff;
      if (uStack_58 == 0xff) {
        if (iVar7 == 0) {
          uStack_58 = 0xffff;
        }
        else {
          iVar4 = uStack_64 - uStack_60;
          if (uStack_64 < uStack_60) {
            iVar4 = uStack_60 - uStack_64;
          }
          uStack_58 = (iVar4 * 10) / (int)(uint)**(byte **)(iVar7 + 8);
        }
      }
      else {
        iVar4 = uStack_64 - uStack_60;
        if (uStack_64 < uStack_60) {
          iVar4 = uStack_60 - uStack_64;
        }
        uStack_58 = (iVar4 * 10) / (int)uStack_58;
      }
_L0:
      uStack_4c = 0;
      uStack_54 = 0;
      uStack_5c = 1;
      uVar9 = uStack_58;
      goto _L0;
    }
    uVar3 = *(undefined1 *)(param_1 + 0x15);
    uStack_70 = uStack_70 & 0xffff0000;
    uStack_68 = 0;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&uStack_68 + 2);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_70,(int)&uStack_68 + 3);
    iVar5 = level_check_options_is_exec(uVar3,bVar1,uStack_68 >> 0x10 & 0xff,uStack_68 >> 0x18);
    if (iVar5 != 0) {
      iVar5 = level_srv_get_attr_desc_part_0(uVar3);
      if (iVar5 == 0) {
        iVar4 = 0x86;
      }
      else {
        zcl_cvc_stop(*(undefined4 *)(iVar5 + 8));
      }
    }
  }
_L0:
  iVar4 = zcl_packet_setup_default_response(auStack_48,param_1,iVar4);
  if (iVar4 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
  return iVar4;
}

