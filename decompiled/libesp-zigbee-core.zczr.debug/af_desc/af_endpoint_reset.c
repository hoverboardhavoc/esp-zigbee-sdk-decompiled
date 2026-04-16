/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_endpoint_reset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_endpoint_reset(uint8_t ep_id,
                           af_endpoint_get_default_attr_value_callback_t get_default_value)

{
  uint16_t *puVar1;
  zcl_cluster_desc_t *cluster_desc;
  af_ep_desc_t *ep_desc;
  ezb_err_t eVar2;
  
  ep_desc = af_get_ep_desc(ep_id);
  if (ep_desc == (af_ep_desc_t *)0x0) {
    eVar2 = 5;
  }
  else {
    puVar1 = (uint16_t *)0x0;
    cluster_desc = (zcl_cluster_desc_t *)0x0;
    while (cluster_desc = af_endpoint_get_next_cluster_desc(ep_desc,cluster_desc),
          cluster_desc != (zcl_cluster_desc_t *)0x0) {
      if (get_default_value == (af_endpoint_get_default_attr_value_callback_t)0x0) {
        return 0;
      }
      while (puVar1 = (uint16_t *)zcl_cluster_get_next_attr_desc(cluster_desc,puVar1),
            puVar1 != (uint16_t *)0x0) {
        if ((*(char *)((int)puVar1 + 3) != '@') && (*puVar1 != 0xfffd)) {
          (*get_default_value)
                    (ep_desc->ep_id,cluster_desc->cluster_id,cluster_desc->role_mask,*puVar1,
                     *(void **)(puVar1 + 4));
          zcl_write_attr_value(*(undefined4 *)(puVar1 + 4),(char)puVar1[1]);
        }
      }
    }
    eVar2 = 0;
  }
  return eVar2;
}

