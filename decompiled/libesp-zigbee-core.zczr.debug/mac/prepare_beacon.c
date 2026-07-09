/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> prepare_beacon
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 prepare_beacon(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  _uStack_24 = CONCAT22(*(undefined2 *)(param_1 + 8),2);
  uStack_28 = *(undefined2 *)(param_1 + 10);
  uStack_26 = 0xffff;
  cVar1 = mac_frame_write_hdr(*param_2,&uStack_24,&uStack_28,0,0,0);
  *(char *)(param_2 + 1) = cVar1 + '\x02';
  *(char *)(param_1 + 0xd) = *(char *)(param_1 + 0xd) + '\x01';
  mac_frame_set_seq_num(param_2);
  iVar4 = *param_2;
  iVar2 = mac_frame_find_payload_index(param_2);
  puVar5 = (undefined1 *)(iVar4 + iVar2);
  iVar2 = mac_is_pan_coord(param_1);
  if (iVar2 == 0) {
    uVar3 = 0xfff;
  }
  else {
    uVar3 = 0x4fff;
  }
  if ((*(ushort *)(param_1 + 0x2a) & 1) != 0) {
    uVar3 = uVar3 | 0x8000;
  }
  *puVar5 = (char)uVar3;
  puVar5[1] = (char)(uVar3 >> 8);
  puVar5[2] = 0;
  puVar5[3] = 0;
  *(char *)(param_2 + 1) = (char)param_2[1] + '\x04';
  cVar1 = mac_beacon_set_payload
                    (puVar5,*(undefined4 *)(param_1 + 0x24),*(undefined1 *)(param_1 + 0x23));
  *(char *)(param_2 + 1) = (char)param_2[1] + cVar1;
  return 0;
}

