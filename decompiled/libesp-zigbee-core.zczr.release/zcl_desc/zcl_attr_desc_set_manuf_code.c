/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_desc.o -> zcl_attr_desc_set_manuf_code
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_attr_desc_set_manuf_code(zcl_attr_desc_t *attr_desc,uint16_t manuf_code)

{
  int iVar1;
  uint16_t extraout_a1;
  ezb_err_t eVar2;
  
  if (attr_desc == (zcl_attr_desc_t *)0x0) {
    attr_desc = (zcl_attr_desc_t *)__assert_func(0,0,0);
    manuf_code = extraout_a1;
  }
  iVar1 = af_device_desc_is_registered();
  eVar2 = 3;
  if (iVar1 == 0) {
    attr_desc->manuf_code = manuf_code;
    eVar2 = 0;
  }
  return eVar2;
}

