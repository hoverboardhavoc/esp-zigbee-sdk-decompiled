/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> on_off.o -> on_off_timer_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t on_off_timer_init(uint8_t ep_id)

{
  uint8_t ep_id_00;
  zcl_attr_desc_t *pzVar1;
  zcl_attr_desc_t *pzVar2;
  uint8_t *puVar3;
  
  pzVar1 = on_off_srv_get_attr_desc(ep_id,0x4001);
  pzVar2 = on_off_srv_get_attr_desc(ep_id,0x4002);
  if ((pzVar1 != (zcl_attr_desc_t *)0x0) && (pzVar2 != (zcl_attr_desc_t *)0x0)) {
    pzVar1 = on_off_srv_get_attr_desc(ep_id,0xeff0);
    if (pzVar1 == (zcl_attr_desc_t *)0x0) {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",0x28b,
                    "on_off_timer_init","on_off_timer_attr_desc");
    }
    else {
      puVar3 = (uint8_t *)calloc(1,0x14);
      pzVar1->data_p = puVar3;
      if (puVar3 != (uint8_t *)0x0) {
        *puVar3 = ep_id;
        milli_timer_init(puVar3 + 4,on_off_timer_handler,puVar3);
        return 0;
      }
    }
    ep_id_00 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/on_off.c",
                             0x28d,"on_off_timer_init","on_off_timer_attr_desc->data_p");
    pzVar1 = on_off_srv_get_attr_desc(ep_id_00,0xeff0);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
      milli_timer_stop((int)pzVar1->data_p + 4);
    }
    return 0;
  }
  return 0;
}

