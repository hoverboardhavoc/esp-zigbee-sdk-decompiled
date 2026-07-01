/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_ctx_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ias_zone_ctx_init(uint8_t ep_id)

{
  void *pvVar1;
  zcl_attr_desc_t *pzVar2;
  ezb_err_t eVar3;
  ezb_err_t extraout_a0;
  int extraout_a1;
  char *new_value;
  
  pvVar1 = calloc(1,0x14);
  if (pvVar1 != (void *)0x0) {
    pzVar2 = ias_zone_srv_get_attr_desc(ep_id,0xeff0);
    pzVar2->data_p = pvVar1;
    return 0;
  }
  new_value = "ias_zone_ctx_init";
  eVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",
                        0x217,"ias_zone_ctx_init","ctx != ((void *)0)");
  if (extraout_a1 == 0x10) {
    ias_zone_cie_address_attr_write_handler
              (*(uint8_t *)(eVar3 + 0x15),*(uint8_t *)(eVar3 + 0x14),*(uint16_t *)(eVar3 + 2),
               new_value);
    eVar3 = extraout_a0;
  }
  return eVar3;
}

