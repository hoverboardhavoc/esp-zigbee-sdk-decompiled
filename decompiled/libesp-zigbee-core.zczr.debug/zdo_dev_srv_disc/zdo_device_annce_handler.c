/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_device_annce_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

undefined4 zdo_device_annce_handler(int param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int local_20;
  int iStack_1c;
  undefined4 uStack_18;
  ushort auStack_14 [2];
  
  auStack_14[0] = 0;
  local_20 = 0;
  iStack_1c = 0;
  uStack_18 = 0;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x14) != 0)) {
    uVar1 = zmsg_get_length();
    af_read_le16(*(undefined4 *)(param_1 + 0x14),auStack_14,&uStack_18);
    af_read_bytes(*(undefined4 *)(param_1 + 0x14),auStack_14,8,&local_20);
    af_read_le8(*(undefined4 *)(param_1 + 0x14),auStack_14,(int)&uStack_18 + 2);
    if (auStack_14[0] <= uVar1) {
      piVar2 = (int *)nwk_get_extended_address();
      if ((*piVar2 != local_20) || (piVar2[1] != iStack_1c)) {
        iVar3 = nwk_is_device_zczr();
        if (iVar3 != 0) {
          auStack_14[1] = 0;
          iVar3 = nwk_address_update(&local_20,uStack_18 & 0xffff,auStack_14 + 1);
          if (iVar3 == 0xd) {
            nwk_raise_address_conflict(uStack_18 & 0xffff);
            return 0xfe;
          }
        }
        zdo_device_annce_indication(local_20,iStack_1c,uStack_18 & 0xffff,uStack_18 >> 0x10 & 0xff);
      }
    }
  }
  return 0xfe;
}

