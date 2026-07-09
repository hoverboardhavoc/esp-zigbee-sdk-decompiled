/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> electrical_measurement.o -> electrical_measurement_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int electrical_measurement_cluster_srv_cmd_proc_handler(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ushort uStack_7e;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined4 *puStack_74;
  undefined1 auStack_70 [36];
  undefined4 uStack_4c;
  undefined1 auStack_48 [8];
  int iStack_40;
  byte abStack_3c [4];
  undefined1 *puStack_38;
  byte abStack_34 [4];
  uint uStack_30;
  undefined4 *puStack_2c;
  uint uStack_28;
  undefined4 *puStack_24;
  
  memset(auStack_70,0,0x28);
  uStack_78 = 0;
  puStack_74 = (undefined4 *)0x0;
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) >> 3 & 1) != 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_70,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (*(char *)(param_1 + 0x20) == '\0') {
    memset(auStack_48,0,0x20);
    uVar5 = zcl_packet_to_message(auStack_48,param_1);
    if (uVar5 == 0) {
      abStack_3c[0] = 0xfe;
      iStack_40 = param_1;
      zcl_core_action_schedule(0x3f,auStack_48);
      uVar5 = (uint)abStack_3c[0];
      if (uVar5 == 0xfe) {
_L0:
        uVar5 = 1;
      }
      else if (uVar5 == 0) {
        if ((puStack_38 == (undefined1 *)0x0) ||
           ((abStack_34[0] != 0 && (*(int *)(puStack_38 + 4) == 0)))) goto _L0;
        uStack_7c = CONCAT31(uStack_7c._1_3_,*puStack_38);
        iVar3 = zmsg_append_bytes(uStack_4c,1,&uStack_7c);
        if (iVar3 == 0) {
          uStack_7c = CONCAT31(uStack_7c._1_3_,puStack_38[1]);
          iVar3 = zmsg_append_bytes(uStack_4c,1,&uStack_7c);
          if (iVar3 == 0) {
            uStack_7c = CONCAT31(uStack_7c._1_3_,puStack_38[2]);
            iVar3 = zmsg_append_bytes(uStack_4c,1,&uStack_7c);
            uVar5 = 0;
            if (iVar3 == 0) {
              for (; uVar5 < abStack_34[0]; uVar5 = uVar5 + 1 & 0xff) {
                uStack_7c = CONCAT22(uStack_7c._2_2_,
                                     *(undefined2 *)(*(int *)(puStack_38 + 4) + uVar5 * 2));
                iVar3 = zmsg_append_bytes(uStack_4c,2,&uStack_7c);
                if (iVar3 != 0) goto _L0;
              }
              uStack_78 = uStack_30;
              puStack_74 = puStack_2c;
              uVar5 = zcl_packet_setup_response(auStack_70,param_1,0);
joined_r0x00010474:
              if (uVar5 == 0) goto _L0;
              goto _L0;
            }
          }
        }
_L0:
        uVar5 = 0x89;
      }
    }
  }
  else if (*(char *)(param_1 + 0x20) == '\x01') {
    memset(auStack_48,0,0x28);
    iVar3 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,2,abStack_3c);
    if (iVar3 == 0) {
      iVar3 = 0xffff;
    }
    iVar4 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),iVar3,4,&puStack_38);
    if (iVar4 == 0) {
      uStack_7e = 0xffff;
    }
    else {
      uStack_7e = (short)iVar3 + (short)iVar4;
    }
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_7e,abStack_34);
    uVar5 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar5 < uStack_7e) {
      uVar5 = 0x80;
    }
    else {
      uVar5 = zcl_packet_to_message(auStack_48,param_1);
      if (uVar5 == 0) {
        uStack_30 = CONCAT31(uStack_30._1_3_,0xfe);
        iStack_40 = param_1;
        zcl_core_action_schedule(0x40,auStack_48);
        uVar2 = uStack_30 & 0xff;
        uVar1 = 1;
        uVar5 = uVar1;
        if ((((uVar2 != 0xfe) && (uVar5 = uVar2, uVar2 == 0)) &&
            (uVar5 = uVar1, puStack_2c != (undefined4 *)0x0)) &&
           ((*(char *)((int)puStack_2c + 6) == '\0' || (puStack_2c[3] != 0)))) {
          uStack_7c = *puStack_2c;
          iVar3 = zmsg_append_bytes(uStack_4c,4,&uStack_7c);
          if (iVar3 == 0) {
            uStack_7c = CONCAT31(uStack_7c._1_3_,*(undefined1 *)(puStack_2c + 1));
            iVar3 = zmsg_append_bytes(uStack_4c,1,&uStack_7c);
            if (iVar3 == 0) {
              uStack_7c = CONCAT31(uStack_7c._1_3_,*(undefined1 *)((int)puStack_2c + 5));
              iVar3 = zmsg_append_bytes(uStack_4c,1,&uStack_7c);
              if (iVar3 == 0) {
                uStack_7c = CONCAT31(uStack_7c._1_3_,*(undefined1 *)((int)puStack_2c + 6));
                iVar3 = zmsg_append_bytes(uStack_4c,1,&uStack_7c);
                if (iVar3 == 0) {
                  uStack_7c = CONCAT22(uStack_7c._2_2_,*(undefined2 *)(puStack_2c + 2));
                  iVar3 = zmsg_append_bytes(uStack_4c,2,&uStack_7c);
                  if (iVar3 == 0) {
                    iVar3 = ezb_zcl_get_attr_desc
                                      (*(undefined1 *)(param_1 + 0x15),0xb04,1,
                                       *(undefined2 *)(puStack_2c + 2),0);
                    uVar5 = 0;
                    if (iVar3 != 0) {
                      for (; uVar5 < *(byte *)((int)puStack_2c + 6); uVar5 = uVar5 + 1 & 0xff) {
                        iVar4 = zcl_packet_append_variable_attr_value
                                          (uStack_4c,*(undefined1 *)(iVar3 + 2),
                                           puStack_2c[3] + uVar5);
                        if (iVar4 != 0) goto _L0;
                      }
                      uStack_78 = uStack_28;
                      puStack_74 = puStack_24;
                      uVar5 = zcl_packet_setup_response(auStack_70,param_1,1);
                      goto joined_r0x00010474;
                    }
                    uVar5 = 0x8b;
                    goto _L0;
                  }
                }
              }
            }
          }
_L0:
          uVar5 = 0x89;
        }
      }
    }
  }
  else {
    uVar5 = 0x81;
  }
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_70,param_1,uVar5);
  if (iVar3 != 0) {
    zcl_packet_free(auStack_70);
    return iVar3;
  }
_L0:
  zcl_packet_send(auStack_70,&uStack_78);
  return 0;
}

