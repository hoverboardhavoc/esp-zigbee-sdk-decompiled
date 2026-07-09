/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_restore(void)

{
  int iVar1;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 auStack_2a [5];
  undefined2 uStack_20;
  undefined1 uStack_1e;
  char cStack_1d;
  undefined2 auStack_1c [4];
  short sStack_14;
  char cStack_12;
  
  iVar1 = core_globals_get();
  sStack_14 = 0;
  cStack_12 = '\0';
  *(byte *)(iVar1 + 0x980) = *(byte *)(iVar1 + 0x980) | 1;
  ds_bind_info_itor_read(&uStack_20);
  while( true ) {
    if (cStack_12 != '\0') {
      iVar1 = core_globals_get();
      *(byte *)(iVar1 + 0x980) = *(byte *)(iVar1 + 0x980) & 0xfe;
      return;
    }
    if (cStack_1d == '\0') {
      memset(&uStack_2b,0,9);
      uStack_2c = 1;
      auStack_2a[0] = auStack_1c[0];
    }
    else {
      uStack_2c = 3;
      memcpy(auStack_2a,auStack_1c,8);
    }
    nwk_get_extended_address();
    iVar1 = aps_bind_table_add(uStack_1e,uStack_20,&uStack_2c,cStack_1d);
    if (iVar1 != 0) break;
    if (cStack_12 == '\0') {
      sStack_14 = sStack_14 + 1;
      ds_bind_info_itor_read(&uStack_20);
    }
  }
  return;
}

