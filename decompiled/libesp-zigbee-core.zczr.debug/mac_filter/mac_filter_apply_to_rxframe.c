/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_apply_to_rxframe
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int mac_filter_apply_to_rxframe(int *param_1)

{
  char cVar1;
  int unaff_s1;
  undefined1 uVar2;
  int iVar3;
  char cStack_19;
  int iStack_18;
  int iStack_14;
  
  iStack_18 = param_1[4];
  iStack_14 = param_1[5];
  cStack_19 = '\0';
  cVar1 = *(char *)((int)param_1 + 0xe);
  if (cVar1 == '\x02') {
    iVar3 = nwk_address_extended_by_short((short)param_1[4],&iStack_18);
    if (iVar3 != 0) {
      return 0;
    }
_L0:
    unaff_s1 = mac_filter_apply(&iStack_18,&cStack_19);
    if (unaff_s1 != 0) {
      return unaff_s1;
    }
  }
  else {
    if (cVar1 == '\x03') goto _L0;
    if (cVar1 != '\0') {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_filter.c",0x107,
                    "mac_filter_apply_to_rxframe",&_LC0);
      goto _L0;
    }
    if (s_restrict_addressless != '\0') {
      return 0x12;
    }
    unaff_s1 = 0;
  }
  if (cStack_19 == '\0') {
    return unaff_s1;
  }
_L0:
  iVar3 = *param_1;
  uVar2 = nwk_lqa_to_lqi();
  *(undefined1 *)(iVar3 + 0x11) = uVar2;
  iVar3 = *param_1;
  uVar2 = nwk_lqa_to_rssi(cStack_19);
  *(undefined1 *)(iVar3 + 0x10) = uVar2;
  return unaff_s1;
}

