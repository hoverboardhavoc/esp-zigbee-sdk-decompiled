/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> custom.o -> ezb_zcl_custom_cluster_handlers_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_custom_cluster_handlers_register(ezb_zcl_custom_cluster_handlers_t *handlers)

{
  ezb_err_t eVar1;
  uint16_t uStack_24;
  uint8_t uStack_22;
  zcl_cluster_template_t template;
  
  if (handlers != (ezb_zcl_custom_cluster_handlers_t *)0x0) {
    uStack_24 = handlers->cluster_id;
    uStack_22 = handlers->cluster_role;
    template._0_4_ = handlers->check_value_cb;
    template.check_value_handler = (zcl_cluster_check_value_t)handlers->write_attr_cb;
    template.write_attr_handler = (zcl_cluster_write_attr_t)handlers->cmd_disc_cb;
    template.cmd_disc_handler = (zcl_cluster_disc_cmd_t)handlers->process_cmd_cb;
    eVar1 = zcl_cluster_template_add(&uStack_24);
    return eVar1;
  }
  return 2;
}

