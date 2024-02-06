/*
 * Last changed at upstream commit d7e241034cb0adc2116988a320badb285c391de3
 * https://github.com/espressif/esp-zigbee-sdk/commit/d7e241034cb0adc2116988a320badb285c391de3
 * Upstream date: 2024-02-06 17:30:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.1(0cd72dc5)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zcl_device_attribute_update_handler
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
    esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC72,uVar3,"ESP_ZIGBEE_CORE",
                  "zcl_device_attribute_update_handler",0x1bc,uStack_1e);
    return 0xffffffe4;
  }
  uStack_1a = (ushort)*(byte *)(iVar2 + 2);
  uStack_18 = 0;
  uVar4 = (uint)*(byte *)(iVar2 + 2);
  if (uVar4 != 0x25) {
    if (0x25 < uVar4) {
      if (uVar4 < 0x4d) {
        if (uVar4 < 0x31) {
          if (uVar4 != 0x2b) {
            if (uVar4 < 0x2c) {
              if (uVar4 == 0x29) goto _L0;
              if (uVar4 == 0x2a) goto _L0;
              if (uVar4 == 0x28) goto _L0;
            }
            else {
              if (uVar4 == 0x2d) goto _L0;
              if (uVar4 == 0x30) {
_L0:
                uStack_16 = 1;
                iStack_14 = iVar1 + 0x10;
                goto _L0;
              }
            }
            goto _L0;
          }
        }
        else {
          uVar4 = 1 << (uVar4 - 0x31 & 0x1f);
          if ((uVar4 & 0x88f0000) != 0) {
            uStack_16 = (ushort)*(byte *)(iVar1 + 0x10);
            iStack_14 = *(int *)(iVar1 + 0x14);
            goto _L0;
          }
          if ((uVar4 & 0x81) != 0) {
_L0:
            uStack_16 = 2;
            iStack_14 = iVar1 + 0x10;
            goto _L0;
          }
          if ((uVar4 & 0x100) == 0) goto _L0;
        }
        goto _L0;
      }
      if (uVar4 == 0xf0) {
        uStack_16 = 8;
        iStack_14 = iVar1 + 0x10;
        goto _L0;
      }
      if (uVar4 < 0xf1) {
        if (uVar4 < 0xea) {
          if (0xe7 < uVar4) goto _L0;
          if (2 < (uVar4 + 0x20 & 0xff)) goto _L0;
        }
        else if (uVar4 != 0xea) goto _L0;
_L0:
        uStack_16 = 4;
        iStack_14 = iVar1 + 0x10;
      }
      else {
_L0:
        uStack_24 = 1;
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"ESP_ZIGBEE_CORE",&_LC73,uVar3,"ESP_ZIGBEE_CORE",*(undefined1 *)(iVar2 + 2))
        ;
      }
      goto _L0;
    }
    if (uVar4 != 0xd) {
      if (uVar4 < 0xe) {
        if (uVar4 == 0) goto _L0;
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

