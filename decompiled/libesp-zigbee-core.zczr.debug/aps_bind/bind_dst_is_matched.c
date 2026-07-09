/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_dst_is_matched
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 bind_dst_is_matched(short *param_1,char *param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iStack_18;
  char *pcStack_14;
  
  cVar1 = *param_2;
  if ((ushort)(cVar1 == '\x01') != ((ushort)param_1[2] >> 8 & 1)) {
    return 0;
  }
  if (cVar1 == '\x01') {
    if (*param_1 == *(short *)(param_2 + 2)) {
      return 1;
    }
    return 0;
  }
  if (cVar1 != '\x03') {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0xc6,
                  "bind_dst_is_matched",&_LC3);
    return 0;
  }
  if ((param_3 != 0xff) && (*(byte *)(param_1 + 1) != param_3)) {
    return 0;
  }
  iVar2 = nwk_address_extended_by_ref(*param_1,&iStack_18);
  if (iVar2 == 0) {
    pcVar4 = *(char **)(param_2 + 6);
    pcVar3 = pcStack_14;
    if (*(int *)(param_2 + 2) != iStack_18) {
      return 0;
    }
  }
  else {
    pcVar4 = "(nwk_address_extended_by_ref(dst->extaddr.addr_ref, &tmp_dst_addr)) == 0";
    pcVar3 = "bind_dst_is_matched";
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0xbe);
  }
  if (pcVar4 != pcVar3) {
    return 0;
  }
  return 1;
}

