/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_core.o -> af_data_indication_deliver_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_data_indication_deliver_handler(af_data_ind_t *ind)

{
  uint8_t *puVar1;
  uint32_t delay_ms;
  
  if (ind == (af_data_ind_t *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/af/af_core.c",0xad,
                  "af_data_indication_deliver_handler",0x102d0);
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

