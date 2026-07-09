/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_restore(void)

{
  int iVar1;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined2 uStack_24;
  undefined2 uStack_20;
  undefined1 uStack_1e;
  char cStack_1d;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  char cStack_12;
  
  iVar1 = core_globals_get();
  *(byte *)(iVar1 + 0x980) = *(byte *)(iVar1 + 0x980) | 1;
  uStack_14 = 0;
  cStack_12 = '\0';
  ds_bind_info_itor_read(&uStack_20);
  while( true ) {
    if (cStack_12 != '\0') {
      iVar1 = core_globals_get();
      *(byte *)(iVar1 + 0x980) = *(byte *)(iVar1 + 0x980) & 0xfe;
      return;
    }
    if (cStack_1d == '\0') {
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_2c = 1;
    }
    else {
      _uStack_2c = CONCAT31(stack0xffffffd5,3);
      uStack_28 = CONCAT22(uStack_18,uStack_1a);
      uStack_24 = uStack_16;
    }
    _uStack_2c = CONCAT22(uStack_1c,uStack_2c);
    nwk_get_extended_address();
    iVar1 = aps_bind_table_add(uStack_1e,uStack_20,&uStack_2c,cStack_1d);
    if (iVar1 != 0) break;
    ds_bind_info_next(&uStack_20);
  }
  return;
}

