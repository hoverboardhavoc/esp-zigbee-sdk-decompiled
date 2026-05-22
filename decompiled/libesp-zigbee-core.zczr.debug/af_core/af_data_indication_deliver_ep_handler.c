/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_indication_deliver_ep_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_data_indication_deliver_ep_handler(void *arg)

{
  uint8_t *puVar1;
  af_data_ind_t *ind;
  uint32_t delay_ms;
  
  if (arg != (void *)0x0) {
    af_data_indication_handler((af_data_ind_t *)arg);
    mm_free(arg);
    return;
  }
  ind = (af_data_ind_t *)
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0x8e,
                      "af_data_indication_deliver_ep_handler",&_L0);
  if (ind == (af_data_ind_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/af/af_core.c",0xad,
                  "af_data_indication_deliver_handler",0x102dc);
  }
  else {
    if ((ind->addr_info).dst_ep != 0xff) {
      af_data_indication_handler(ind);
      return;
    }
    delay_ms = 0;
    puVar1 = (uint8_t *)0x0;
    while (puVar1 = (uint8_t *)af_device_get_next_endpoint_desc(puVar1), puVar1 != (uint8_t *)0x0) {
      if ((*puVar1 != 0xff) && (*(uint16_t *)(puVar1 + 2) == (ind->addr_info).profile_id)) {
        af_data_indication_deliver_ep(ind,*puVar1,delay_ms);
        delay_ms = random_add_jitter(delay_ms,10);
      }
    }
  }
  zmsg_free(ind->asdu);
  return;
}

