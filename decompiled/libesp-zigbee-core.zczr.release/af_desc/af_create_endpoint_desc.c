/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_create_endpoint_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

af_ep_desc_t * af_create_endpoint_desc(af_ep_config_t *ep_config)

{
  af_ep_desc_t *paVar1;
  af_ep_config_t *__dest;
  
  paVar1 = (af_ep_desc_t *)calloc(1,0x1c);
  if (paVar1 != (af_ep_desc_t *)0x0) {
    paVar1->ep_id = ep_config->ep_id;
    paVar1->profile_id = ep_config->app_profile_id;
    __dest = (af_ep_config_t *)calloc(1,8);
    if (__dest != (af_ep_config_t *)0x0) {
      memcpy(__dest,ep_config,8);
      paVar1->ep_config = __dest;
      paVar1->next = (af_ep_desc_s *)0x0;
      return paVar1;
    }
    mm_free(paVar1);
  }
  return (af_ep_desc_t *)0x0;
}

