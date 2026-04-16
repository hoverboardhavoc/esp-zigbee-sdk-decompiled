/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> esp_zb_zcl_custom_cluster_handlers_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: handlers */
/* WARNING: Unknown calling convention */

esp_err_t esp_zb_zcl_custom_cluster_handlers_update(esp_zb_zcl_custom_cluster_handlers_t *obj)

{
  uint3 uVar1;
  uint3 *in_a0;
  esp_err_t eVar2;
  uint uStack_24;
  ezb_zcl_custom_cluster_handlers_t handlers;
  
  uVar1 = *in_a0;
  zcl_cluster_template_remove((short)*in_a0,*(undefined1 *)((int)in_a0 + 2));
  handlers.write_attr_cb = (ezb_zcl_custom_cluster_write_attr_t)0x0;
  uStack_24 = (uint)uVar1;
  handlers._0_4_ = *(undefined4 *)(in_a0 + 1);
  handlers.check_value_cb = *(ezb_zcl_custom_cluster_check_value_t *)(in_a0 + 2);
  handlers.cmd_disc_cb = (ezb_zcl_custom_cluster_disc_cmd_t)&zb_zcl_custom_cluster_cmd_handler;
  ezb_zcl_custom_cluster_handlers_register(&uStack_24);
  eVar2 = esp_zigbee_err_to_esp();
  return eVar2;
}

