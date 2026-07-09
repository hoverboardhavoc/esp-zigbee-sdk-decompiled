/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_dup.o -> aps_dup_table_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void aps_dup_table_deinit(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  time_ticker_unregister_receiver(4);
  iVar1 = core_globals_get();
  iVar3 = *(int *)(iVar1 + 0x984);
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0x988);
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0x98c) != 0) && (iVar3 != 0)) && (iVar1 != 0)) {
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0x984));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x984) = 0;
    iVar1 = core_globals_get();
    mm_free(*(undefined4 *)(iVar1 + 0x988));
    iVar1 = core_globals_get();
    *(undefined4 *)(iVar1 + 0x988) = 0;
    return;
  }
  __assert_func(0,0,0,0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

