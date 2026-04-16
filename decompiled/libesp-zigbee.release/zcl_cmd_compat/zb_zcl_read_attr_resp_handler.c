/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_read_attr_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zb_zcl_read_attr_resp_handler(void *arg,esp_zb_core_action_callback_t cb)

{
  void *next;
  undefined4 uVar1;
  undefined2 *puVar2;
  ezb_zcl_status_t eVar3;
  undefined2 uVar4;
  undefined1 *puVar5;
  esp_err_t err;
  undefined1 auStack_44 [4];
  esp_zb_zcl_cmd_read_attr_resp_message_t app_message;
  
  memset(auStack_44,0,0x24);
  convert_to_esp_zb_zcl_cmd_info
            ((esp_zb_zcl_cmd_info_t *)auStack_44,*(ezb_zcl_cmd_hdr_t **)((int)arg + 8));
                    /* WARNING: Load size is inaccurate */
  auStack_44[0] = *arg;
  puVar2 = *(undefined2 **)((int)arg + 0xc);
  do {
    if (puVar2 == (undefined2 *)0x0) {
_L0:
      if (cb != (esp_zb_core_action_callback_t)0x0) {
        err = (*cb)(ESP_ZB_CORE_CMD_READ_ATTR_RESP_CB_ID,auStack_44);
        eVar3 = esp_err_to_zcl_status(err);
        *(ezb_zcl_status_t *)((int)arg + 0x10) = eVar3;
      }
      while (app_message.info._28_4_ != 0) {
        uVar1 = *(undefined4 *)(app_message.info._28_4_ + 0x10);
        free((void *)app_message.info._28_4_);
        app_message.info._28_4_ = uVar1;
      }
      return;
    }
    puVar5 = (undefined1 *)malloc(0x14);
    if (puVar5 == (undefined1 *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","read attr resp: malloc failed");
      goto _L0;
    }
    *puVar5 = *(undefined1 *)(puVar2 + 1);
    uVar1 = *(undefined4 *)(puVar2 + 2);
    *(undefined2 *)(puVar5 + 4) = *puVar2;
    *(undefined4 *)(puVar5 + 0xc) = uVar1;
    puVar5[8] = *(undefined1 *)((int)puVar2 + 3);
    uVar4 = ezb_zcl_get_attr_value_size();
    puVar2 = *(undefined2 **)(puVar2 + 4);
    *(undefined2 *)(puVar5 + 10) = uVar4;
    *(undefined4 *)(puVar5 + 0x10) = app_message.info._28_4_;
    app_message.info._28_4_ = puVar5;
  } while( true );
}

