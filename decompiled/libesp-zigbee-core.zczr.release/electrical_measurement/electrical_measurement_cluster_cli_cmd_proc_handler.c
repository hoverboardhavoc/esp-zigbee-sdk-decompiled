/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> electrical_measurement.o -> electrical_measurement_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int electrical_measurement_cluster_cli_cmd_proc_handler(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort uStack_6a;
  undefined1 auStack_68 [8];
  int iStack_60;
  undefined1 uStack_5c;
  undefined1 uStack_5b;
  undefined1 auStack_5a [2];
  undefined4 uStack_58;
  byte abStack_54 [4];
  void *pvStack_50;
  byte bStack_4c;
  undefined1 auStack_48 [48];
  
  memset(auStack_48,0,0x28);
  if (param_1 == 0) {
    return 1;
  }
  if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
    return 1;
  }
  iVar2 = zcl_packet_init(auStack_48,*(byte *)(param_1 + 0x1a) >> 2 & 1);
  if (iVar2 != 0) {
    return iVar2;
  }
  if (*(char *)(param_1 + 0x20) != '\0') {
    if (*(char *)(param_1 + 0x20) != '\x01') {
      uVar4 = 0x81;
      goto _L0;
    }
    memset(auStack_68,0,0x20);
    iVar2 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),0,4,&uStack_5c);
    if (iVar2 == 0) {
      iVar2 = 0xffff;
    }
    uStack_6a = (ushort)iVar2;
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_6a,&uStack_58);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_6a,(int)&uStack_58 + 1);
    af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_6a,(int)&uStack_58 + 2);
    uVar4 = (uint)uStack_6a;
    iVar2 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar4,2,abStack_54);
    if (iVar2 == 0) {
      uVar1 = 0xffff;
    }
    else {
      uVar1 = uVar4 + iVar2 & 0xffff;
    }
    uStack_6a = (ushort)uVar1;
    uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar4 = 0x80;
    if (uVar1 <= uVar3) {
      if (((uint)uStack_58 >> 0x10 & 0xff) != 0) {
        iVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
        uVar3 = iVar2 - uVar1 & 0xffff;
        pvStack_50 = calloc(uVar3,1);
        uVar4 = 0x89;
        if (pvStack_50 == (void *)0x0) goto _L0;
        iVar2 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar1,uVar3,pvStack_50);
        if ((iVar2 == 0) && (uVar3 != 0)) {
          uStack_6a = 0xffff;
        }
        else {
          uStack_6a = (ushort)uVar1 + (short)iVar2;
        }
      }
      uVar4 = zcl_packet_to_message(auStack_68,param_1);
      if (uVar4 == 0) {
        bStack_4c = 0xfe;
        iStack_60 = param_1;
        zcl_core_action_schedule(0x42,auStack_68);
        if (bStack_4c != 0xfe) {
          uVar4 = (uint)bStack_4c;
        }
      }
    }
_L0:
    if (pvStack_50 != (void *)0x0) {
      mm_free();
    }
    goto _L0;
  }
  memset(auStack_68,0,0x18);
  uStack_6a = 0;
  af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_6a,&uStack_5c);
  af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_6a,&uStack_5b);
  af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_6a,auStack_5a);
  uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  uVar1 = (uint)uStack_6a;
  uVar4 = 0x80;
  if (uVar1 <= uVar3) {
    iVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar3 = iVar2 - uVar1 >> 1 & 0xffff;
    if (uVar3 != 0) {
      uStack_58 = calloc(uVar3,2);
      uVar4 = 0x89;
      if (uStack_58 == (void *)0x0) goto _L0;
      uVar4 = 0;
      do {
        iVar2 = zmsg_read_bytes(*(undefined4 *)(param_1 + 0x24),uVar1,2,
                                (void *)(uVar4 * 2 + (int)uStack_58));
        uVar5 = 0xffff;
        if (iVar2 != 0) {
          uVar5 = uVar1 + iVar2 & 0xffff;
        }
        uVar4 = uVar4 + 1;
        uStack_6a = (ushort)uVar5;
        uVar1 = uVar5;
      } while ((uVar4 & 0xffff) < uVar3);
    }
    uVar4 = zcl_packet_to_message(auStack_68,param_1);
    if (uVar4 == 0) {
      abStack_54[0] = 0xfe;
      iStack_60 = param_1;
      zcl_core_action_schedule(0x41,auStack_68);
      if (abStack_54[0] != 0xfe) {
        uVar4 = (uint)abStack_54[0];
      }
    }
  }
_L0:
  if (uStack_58 != (void *)0x0) {
    mm_free();
  }
_L0:
  iVar2 = zcl_packet_setup_default_response(auStack_48,param_1,uVar4);
  if (iVar2 == 0) {
    zcl_packet_send(auStack_48,0);
  }
  else {
    zcl_packet_free(auStack_48);
  }
  return iVar2;
}

