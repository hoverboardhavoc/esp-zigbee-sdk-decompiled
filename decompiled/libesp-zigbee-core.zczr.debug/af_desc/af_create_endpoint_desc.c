/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_create_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_ep_desc_t * af_create_endpoint_desc(af_ep_config_t *ep_config)

{
  af_ep_desc_t *paVar1;
  
  paVar1 = (af_ep_desc_t *)calloc(1,0x20);
  if (paVar1 != (af_ep_desc_t *)0x0) {
    paVar1->ep_id = ep_config->ep_id;
    paVar1->profile_id = ep_config->app_profile_id;
    memset(&paVar1->simple_desc,0,0x10);
    (paVar1->simple_desc).ep_id = ep_config->ep_id;
    (paVar1->simple_desc).app_profile_id = ep_config->app_profile_id;
    (paVar1->simple_desc).app_device_id = ep_config->app_device_id;
    (paVar1->simple_desc).field_0x6 =
         (paVar1->simple_desc).field_0x6 & 0xf0 | (byte)*(undefined2 *)&ep_config->field_0x6 & 0xf;
    paVar1->next = (af_ep_desc_s *)0x0;
  }
  return paVar1;
}

