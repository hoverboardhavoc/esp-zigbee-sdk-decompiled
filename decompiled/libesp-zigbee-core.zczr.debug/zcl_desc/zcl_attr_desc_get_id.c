/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_attr_desc_get_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

uint zcl_attr_desc_get_id(ushort *param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 != (ushort *)0x0) {
    return (uint)*param_1;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x82,
                        "zcl_attr_desc_get_id","attr_desc");
  if (iVar1 != 0) {
    uVar2 = zcl_get_attr_value_size(*(undefined1 *)(iVar1 + 2),*(undefined4 *)(iVar1 + 8));
    return uVar2;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x88,"attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

