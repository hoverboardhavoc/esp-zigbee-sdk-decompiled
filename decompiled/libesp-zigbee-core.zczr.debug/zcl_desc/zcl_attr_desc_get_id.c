/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_attr_desc_get_id
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

uint16_t zcl_attr_desc_get_id(zcl_attr_desc_t *attr_desc)

{
  uint16_t uVar1;
  int iVar2;
  
  if (attr_desc != (zcl_attr_desc_t *)0x0) {
    return attr_desc->id;
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x82,
                        "zcl_attr_desc_get_id","attr_desc");
  if (iVar2 != 0) {
    uVar1 = zcl_get_attr_value_size(*(undefined1 *)(iVar2 + 2),*(undefined4 *)(iVar2 + 8));
    return uVar1;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x88,"attr_desc");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

