/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_attr_desc_set_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_attr_desc_set_value(zcl_attr_desc_t *attr_desc,void *value)

{
  int iVar1;
  
  if (attr_desc == (zcl_attr_desc_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_desc.c",0x95,
                  "zcl_attr_desc_set_value","attr_desc");
  }
  else {
    iVar1 = af_device_desc_is_registered();
    if (iVar1 == 0) {
      iVar1 = zcl_write_attr_value(attr_desc->data_p,value,attr_desc->type);
      if (iVar1 != 0) {
        return 0;
      }
      return -1;
    }
  }
  return 3;
}

