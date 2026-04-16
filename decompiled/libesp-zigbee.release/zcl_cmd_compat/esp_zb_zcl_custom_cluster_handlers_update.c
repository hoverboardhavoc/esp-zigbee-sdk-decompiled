/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_custom_cluster_handlers_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: handlers */

esp_err_t esp_zb_zcl_custom_cluster_handlers_update(esp_zb_zcl_custom_cluster_handlers_t obj)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 *in_a0;
  esp_err_t eVar3;
  undefined2 uStack_24;
  undefined1 uStack_22;
  undefined1 uStack_21;
  ezb_zcl_custom_cluster_handlers_t handlers;
  
  uVar1 = *(undefined1 *)(in_a0 + 1);
  uVar2 = *in_a0;
  zcl_cluster_template_remove(uVar2,uVar1);
  memset(&uStack_21,0,0xd);
  handlers._0_4_ = *(undefined4 *)(in_a0 + 2);
  handlers.check_value_cb = *(ezb_zcl_custom_cluster_check_value_t *)(in_a0 + 4);
  handlers.cmd_disc_cb = (ezb_zcl_custom_cluster_disc_cmd_t)&zb_zcl_custom_cluster_cmd_handler;
  uStack_24 = uVar2;
  uStack_22 = uVar1;
  ezb_zcl_custom_cluster_handlers_register(&uStack_24);
  eVar3 = esp_zigbee_err_to_esp();
  return eVar3;
}

