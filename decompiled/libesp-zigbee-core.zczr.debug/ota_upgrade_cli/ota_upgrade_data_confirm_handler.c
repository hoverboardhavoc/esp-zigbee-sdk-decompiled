/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_data_confirm_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ota_upgrade_data_confirm_handler
               (zcl_packet_cnf_t *cnf,ota_upgrade_downloading_context_t *context)

{
  uint8_t extraout_a0;
  uint8_t ep_id;
  ota_upgrade_downloading_context_t *poVar1;
  
  poVar1 = context;
  if ((cnf == (zcl_packet_cnf_t *)0x0) || (context == (ota_upgrade_downloading_context_t *)0x0)) {
    context = (ota_upgrade_downloading_context_t *)
              __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                            ,0x171,"ota_upgrade_data_confirm_handler","cnf && context");
    ep_id = extraout_a0;
  }
  else {
    ep_id = cnf->src_ep;
    if (cnf->status != '\0') {
      ota_upgrade_downloading_abort(ep_id);
      return;
    }
  }
  (context->error).req.ep_id = ep_id;
  (context->error).req.tsn = cnf->tsn;
  milli_timer_start(&(poVar1->error).req.timeout,5000);
  return;
}

