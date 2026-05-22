/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_attr_desc_get_access
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t zcl_attr_desc_get_access(zcl_attr_desc_t *attr_desc)

{
  int iVar1;
  int iVar2;
  undefined1 extraout_a1;
  
  if (attr_desc != (zcl_attr_desc_t *)0x0) {
    return attr_desc->access;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0xa4,
                        "zcl_attr_desc_get_access","attr_desc");
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0xab,
                  "zcl_attr_desc_set_access","attr_desc");
  }
  else {
    iVar2 = af_device_desc_is_registered();
    if (iVar2 == 0) {
      *(undefined1 *)(iVar1 + 3) = extraout_a1;
      return '\0';
    }
  }
  return '\x03';
}

