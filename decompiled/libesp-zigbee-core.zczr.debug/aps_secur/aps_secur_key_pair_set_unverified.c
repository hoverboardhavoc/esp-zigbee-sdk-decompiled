/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_unverified
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_unverified(int param_1,void *param_2)

{
  ushort uVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if (param_1 != 0) {
    memcpy((void *)(param_1 + 0x12),param_2,0x10);
    uVar1 = *(ushort *)(param_1 + 0x34);
    *(ushort *)(param_1 + 0x34) = uVar1 & 0xfffe;
    *(ushort *)(param_1 + 0x34) = uVar1 & 0xfff8 | 2;
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    iVar4 = core_globals_get();
    aps_secur_key_pair_set_timeout(param_1,*(undefined1 *)(iVar4 + 0x9b4));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_secur.c",0x15d,
                "aps_secur_key_pair_set_unverified","key_pair != ((void *)0)");
  iVar4 = core_globals_get();
  uVar6 = 0;
  bVar3 = true;
  while( true ) {
    uVar6 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar4 + 0x9a4),*(undefined2 *)(iVar4 + 0x9a8),uVar6);
    if (*(ushort *)(iVar4 + 0x9a8) <= uVar6) break;
    iVar5 = *(int *)(iVar4 + 0x9a0) + uVar6 * 0x38;
    sVar2 = *(short *)(iVar5 + 0x10);
    if (sVar2 != -1) {
      if (sVar2 != 0) {
        *(short *)(iVar5 + 0x10) = sVar2 + -1;
      }
      if (*(short *)(iVar5 + 0x10) == 0) {
        aps_secur_delete_key_pair();
      }
      else {
        bVar3 = false;
      }
    }
    uVar6 = uVar6 + 1 & 0xffff;
  }
  if (bVar3) {
    time_ticker_unregister_receiver(3);
  }
  return;
}

