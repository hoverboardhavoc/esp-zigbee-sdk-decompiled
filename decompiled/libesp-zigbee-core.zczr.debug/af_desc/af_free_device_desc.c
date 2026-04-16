/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_free_device_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void af_free_device_desc(af_device_desc_t *dev_desc)

{
  af_ep_desc_s *paVar1;
  af_ep_desc_t *ep_desc;
  
  if (dev_desc != (af_device_desc_t *)0x0) {
    ep_desc = (af_ep_desc_t *)dev_desc->ep_list;
    while (ep_desc != (af_ep_desc_t *)0x0) {
      paVar1 = ep_desc->next;
      af_free_endpoint_desc(ep_desc);
      ep_desc = paVar1;
    }
    mm_free(dev_desc);
  }
  return;
}

