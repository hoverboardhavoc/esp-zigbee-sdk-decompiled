/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> metering_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int metering_cluster_cli_cmd_proc_handler(int param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  ushort uStack_a2;
  undefined1 auStack_a0 [40];
  undefined1 auStack_78 [8];
  int iStack_70;
  undefined1 auStack_6c [4];
  undefined1 auStack_68 [4];
  byte abStack_64 [2];
  undefined1 auStack_62 [2];
  undefined2 uStack_60;
  undefined1 auStack_5e [2];
  void *pvStack_5c;
  byte abStack_58 [8];
  undefined1 auStack_50 [12];
  int iStack_44;
  void *pvStack_3c;
  int iStack_34;
  void *pvStack_2c;
  byte bStack_28;
  
  memset(auStack_a0,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar3 = zcl_packet_init(auStack_a0,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar3 != 0) {
    return iVar3;
  }
  bVar1 = *(byte *)(param_1 + 0x20);
  if (bVar1 == 6) {
    memset(auStack_78,0,0x58);
    uStack_a2 = 0;
    iVar3 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_68);
    if ((((iVar3 != 4) ||
         (iVar3 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a2,abStack_64), iVar3 != 4))
        || (iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_60), iVar3 != 1))
       || (((iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,(int)&uStack_60 + 1),
            iVar3 != 1 ||
            (iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_5e), iVar3 != 1)
            ) || ((iVar3 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&pvStack_5c),
                  iVar3 != 4 ||
                  (iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,abStack_58),
                  iVar3 != 1)))))) {
      uVar4 = 0x80;
      goto _L0;
    }
    if (abStack_58[0] == 4) {
_L0:
      uVar4 = parse_tou_info_no_billing_set_from_payload
                        (*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_50);
      iVar3 = iStack_44;
joined_r0x00010b5e:
      if (uVar4 != 0) goto _L0;
      pvVar5 = (void *)0x0;
    }
    else {
      if (abStack_58[0] < 5) {
        if ((abStack_58[0] != 2) && (abStack_58[0] != 3)) {
          uVar4 = parse_tou_info_set_from_payload(&uStack_a2,auStack_50);
          iVar3 = iStack_34;
          goto joined_r0x00010b5e;
        }
        uVar4 = parse_block_info_set_from_payload
                          (*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_50);
        iVar3 = iStack_34;
        pvVar5 = pvStack_2c;
      }
      else {
        if ((abStack_58[0] != 6) && (abStack_58[0] != 7)) {
          uVar4 = 0x87;
          if (abStack_58[0] != 5) goto _L0;
          goto _L0;
        }
        uVar4 = parse_block_info_no_billing_set_from_payload
                          (*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_50);
        iVar3 = iStack_44;
        pvVar5 = pvStack_3c;
      }
      if (uVar4 != 0) goto _L0;
    }
    uVar4 = zcl_packet_to_message(auStack_78,param_1);
    if (uVar4 == 0) {
      bStack_28 = 0xfe;
      iStack_70 = param_1;
      zcl_core_action_schedule(0x48,auStack_78);
      if (bStack_28 != 0xfe) {
        uVar4 = (uint)bStack_28;
      }
    }
    if (iVar3 != 0) {
      mm_free(iVar3);
    }
joined_r0x00010bbc:
    if (pvVar5 != (void *)0x0) {
      mm_free(pvVar5);
    }
    goto _L0;
  }
  if (bVar1 < 7) {
    if (bVar1 == 0) {
      memset(auStack_78,0,0x24);
      uStack_a2 = 0;
      iVar3 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_6c);
      if ((((iVar3 == 0) ||
           (iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_68), iVar3 == 0))
          || (iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,abStack_64), iVar3 == 0
             )) || (iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_60),
                   iVar3 == 0)) {
_L0:
        uVar4 = 0x80;
      }
      else {
        iVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        uVar4 = (uint)(byte)uStack_60;
        if (iVar3 < (int)((uint)uStack_a2 + uVar4 * 3)) goto _L0;
        if (uVar4 == 0) {
_L0:
          uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
          if (uVar4 < uStack_a2) goto _L0;
          uVar4 = zcl_packet_to_message(auStack_78,param_1);
          if (uVar4 == 0) {
            abStack_58[0] = 0xfe;
            iStack_70 = param_1;
            zcl_core_action_schedule(0x44,auStack_78);
            if (abStack_58[0] != 0xfe) {
              uVar4 = (uint)abStack_58[0];
            }
          }
        }
        else {
          pvStack_5c = calloc(uVar4,4);
          uVar4 = 0x89;
          uVar2 = 0;
          if (pvStack_5c != (void *)0x0) {
            while( true ) {
              if ((byte)uStack_60 <= uVar2) break;
              iVar3 = zcl_packet_read_variable_attr_value
                                (*(undefined4 *)(param_1 + 0x24),&uStack_a2,0x22,
                                 (void *)(uVar2 * 4 + (int)pvStack_5c));
              if (iVar3 == 0) goto _L0;
              uVar2 = uVar2 + 1 & 0xff;
            }
            goto _L0;
          }
        }
      }
      if (pvStack_5c != (void *)0x0) {
        mm_free();
      }
      goto _L0;
    }
    if (bVar1 == 3) {
      memset(auStack_78,0,0x18);
      uStack_a2 = 0;
      iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_6c);
      if (((iVar3 == 0) ||
          (iVar3 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_68), iVar3 == 0))
         || (uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24)), uVar4 < uStack_a2)) {
        uVar4 = 0x80;
      }
      else {
        uVar4 = zcl_packet_to_message(auStack_78,param_1);
        if (uVar4 == 0) {
          abStack_64[0] = 0xfe;
          iStack_70 = param_1;
          zcl_core_action_schedule(0x46,auStack_78,0);
          if (abStack_64[0] != 0xfe) {
            uVar4 = (uint)abStack_64[0];
          }
        }
      }
      goto _L0;
    }
  }
  else if (bVar1 == 7) {
    memset(auStack_78,0,0x24);
    uStack_a2 = 0;
    iVar3 = af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_6c);
    if ((((iVar3 != 0) &&
         (iVar3 = af_read_le32(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_68), iVar3 != 0))
        && (iVar3 = af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_a2,abStack_64), iVar3 != 0))
       && ((iVar3 = af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_a2,auStack_62), iVar3 != 0
           && (iVar3 = af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_a2,&uStack_60),
              iVar3 != 0)))) {
      iVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
      uVar4 = (uint)uStack_60;
      if ((int)((uint)uStack_a2 + uVar4 * 3) <= iVar3) {
        if (uVar4 != 0) {
          pvStack_5c = calloc(uVar4,4);
          uVar4 = 0x89;
          pvVar5 = pvStack_5c;
          if (pvStack_5c == (void *)0x0) goto joined_r0x00010bbc;
          for (uVar4 = 0; uVar4 < uStack_60; uVar4 = uVar4 + 1 & 0xffff) {
            iVar3 = zcl_packet_read_variable_attr_value
                              (*(undefined4 *)(param_1 + 0x24),&uStack_a2,0x22,
                               (void *)(uVar4 * 4 + (int)pvStack_5c));
            if (iVar3 == 0) goto _L0;
          }
        }
        uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        if (uStack_a2 <= uVar4) {
          uVar4 = zcl_packet_to_message(auStack_78,param_1);
          pvVar5 = pvStack_5c;
          if (uVar4 == 0) {
            abStack_58[0] = 0xfe;
            iStack_70 = param_1;
            zcl_core_action_schedule(0x4a,auStack_78);
            pvVar5 = pvStack_5c;
            if (abStack_58[0] != 0xfe) {
              uVar4 = (uint)abStack_58[0];
            }
          }
          goto joined_r0x00010bbc;
        }
      }
    }
_L0:
    uVar4 = 0x80;
    pvVar5 = pvStack_5c;
    goto joined_r0x00010bbc;
  }
  uVar4 = 0x81;
_L0:
  iVar3 = zcl_packet_setup_default_response(auStack_a0,param_1,uVar4);
  if (iVar3 == 0) {
    zcl_packet_send(auStack_a0,0);
  }
  else {
    zcl_packet_free(auStack_a0);
  }
  return iVar3;
}

