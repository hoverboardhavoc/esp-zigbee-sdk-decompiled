/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_filter.o -> mac_filter_apply_to_rxframe
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_filter_apply_to_rxframe(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iStack_18;
  int iStack_14;
  
  iStack_18 = param_1[4];
  iStack_14 = param_1[5];
  uVar4 = (uint)*(byte *)((int)param_1 + 0xe);
  if (uVar4 == 2) {
    iVar3 = nwk_address_extended_by_short((short)param_1[4],&iStack_18);
    if (iVar3 != 0) {
      return 0;
    }
_L0:
    iVar3 = mac_filter_find_entry(&iStack_18);
    uVar4 = 0;
    if (iVar3 != 0) {
      uVar4 = (uint)*(byte *)(iVar3 + 9);
    }
    if (s_filter_mode != '\x01') {
      if (s_filter_mode == '\x02') {
        if (uVar4 != 0) {
          return 0x12;
        }
        goto _L0;
      }
      if (s_filter_mode == '\0') goto _L0;
      goto _L0;
    }
  }
  else {
    if (uVar4 == 3) goto _L0;
    if (uVar4 == 0) {
      if (s_restrict_addressless != '\0') {
        return 0x12;
      }
      return 0;
    }
_L0:
    iVar3 = __assert_func(0,0,0,0);
  }
  if (uVar4 == 0) {
    return 0x12;
  }
_L0:
  if ((iVar3 != 0) && (cVar1 = *(char *)(iVar3 + 8), cVar1 != '\0')) {
    iVar5 = *param_1;
    uVar2 = nwk_lqa_to_lqi(cVar1);
    iVar3 = *param_1;
    *(undefined1 *)(iVar5 + 0x11) = uVar2;
    uVar2 = nwk_lqa_to_rssi(cVar1);
    *(undefined1 *)(iVar3 + 0x10) = uVar2;
  }
  return 0;
}

