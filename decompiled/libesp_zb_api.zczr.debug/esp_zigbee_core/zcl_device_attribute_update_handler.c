/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> zcl_device_attribute_update_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_device_attribute_update_handler(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uStack_24;
  undefined1 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  ushort uStack_1a;
  undefined2 uStack_18;
  ushort uStack_16;
  int iStack_14;
  
  iVar1 = zb_buf_get_tail_func(0x38);
  uStack_24 = 0;
  uStack_20 = *(undefined1 *)(iVar1 + 4);
  uStack_1e = *(undefined2 *)(iVar1 + 0xc);
  uStack_1c = *(undefined2 *)(iVar1 + 0xe);
  uStack_1a = 0;
  uStack_18 = 0;
  uStack_16 = 0;
  iStack_14 = 0;
  iVar2 = find_device_endpoint_cluster_attribute();
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_L0,uVar3,"ESP_ZIGBEE_CORE",
                  "zcl_device_attribute_update_handler",0xfc,uStack_1e);
    return 0xffffffe4;
  }
  uStack_1a = (ushort)*(byte *)(iVar2 + 2);
  uStack_18 = 0;
  uVar4 = (uint)*(byte *)(iVar2 + 2);
  if (uVar4 != 0x25) {
    if (0x25 < uVar4) {
      if (uVar4 < 0x52) {
        if (0x38 < uVar4) {
          uVar4 = 1 << (uVar4 - 0x39 & 0x1f);
          if ((uVar4 & 0x1888f00) != 0) {
_L0:
            uStack_16 = (ushort)*(byte *)(iVar1 + 0x10);
            iStack_14 = *(int *)(iVar1 + 0x14);
            goto _L0;
          }
          if ((uVar4 & 2) == 0) {
            if ((uVar4 & 1) != 0) goto _L0;
            goto _L0;
          }
_L0:
          uStack_16 = 8;
          iStack_14 = iVar1 + 0x10;
          goto _L0;
        }
        if (uVar4 == 0x2d) goto _L0;
        if (uVar4 < 0x2e) {
          if (uVar4 == 0x2a) goto _L0;
          if (uVar4 < 0x2b) {
            if (uVar4 == 0x28) goto _L0;
            if (uVar4 == 0x29) goto _L0;
          }
          else if (uVar4 == 0x2b) goto _L0;
        }
        else {
          if ((uVar4 == 0x31) || (uVar4 == 0x38)) {
_L0:
            uStack_16 = 2;
            iStack_14 = iVar1 + 0x10;
            goto _L0;
          }
          if (uVar4 == 0x30) {
_L0:
            uStack_16 = 1;
            iStack_14 = iVar1 + 0x10;
            goto _L0;
          }
        }
      }
      else {
        if (uVar4 == 0xf0) goto _L0;
        if (uVar4 < 0xf1) {
          if (uVar4 < 0xea) {
            if (0xe7 < uVar4) goto _L0;
            if ((uVar4 + 0x20 & 0xff) < 3) goto _L0;
          }
          else if (uVar4 == 0xea) {
_L0:
            uStack_16 = 4;
            iStack_14 = iVar1 + 0x10;
            goto _L0;
          }
        }
        else if (uVar4 == 0xf1) goto _L0;
      }
_L0:
      uStack_24 = 1;
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC5,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(iVar2 + 2));
      goto _L0;
    }
    if (uVar4 != 0xd) {
      if (uVar4 < 0xe) {
        if (uVar4 == 0) {
          uStack_16 = 0;
          iStack_14 = 0;
          goto _L0;
        }
        if (uVar4 != 10) {
          if (uVar4 < 0xb) {
            if (uVar4 == 8) goto _L0;
            if (uVar4 == 9) goto _L0;
          }
          else if (uVar4 == 0xb) goto _L0;
          goto _L0;
        }
_L0:
        uStack_16 = 3;
        iStack_14 = iVar1 + 0x10;
        goto _L0;
      }
      if (uVar4 != 0x1d) {
        if (uVar4 < 0x1e) {
          if (uVar4 == 0x19) goto _L0;
          if (uVar4 < 0x1a) {
            if ((uVar4 == 0x10) || (uVar4 == 0x18)) goto _L0;
          }
          else {
            if (uVar4 == 0x1a) goto _L0;
            if (uVar4 == 0x1b) goto _L0;
          }
        }
        else {
          if (uVar4 == 0x22) goto _L0;
          if (uVar4 < 0x23) {
            if (uVar4 == 0x20) goto _L0;
            if (uVar4 == 0x21) goto _L0;
          }
          else if (uVar4 == 0x23) goto _L0;
        }
        goto _L0;
      }
    }
  }
_L0:
  uStack_16 = 6;
  iStack_14 = iVar1 + 0x10;
_L0:
  if (zb_core_action_cb == (code *)0x0) {
    uVar3 = 0;
  }
  else {
    (*zb_core_action_cb)(0,&uStack_24);
    uVar3 = esp_err_to_zb_ret();
  }
  return uVar3;
}

