/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> radio_spinel_transmit_failed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void radio_spinel_transmit_failed(esp_ieee802154_tx_error_t error)

{
  undefined4 unaff_retaddr;
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if (ESP_IEEE802154_TX_ERR_INVALID_ACK < error) goto _L0;
  uVar2 = 0x1e9;
  if (error < ESP_IEEE802154_TX_ERR_NO_ACK) {
    uVar2 = 0x1e1;
    puVar1 = (undefined1 *)register0x00002008;
    if (1 < error - ESP_IEEE802154_TX_ERR_CCA_BUSY) {
      do {
        register0x00002008 = (BADSPACEBASE *)(puVar1 + -0x10);
        *(undefined4 *)(puVar1 + -4) = unaff_retaddr;
        unaff_retaddr = 0x10068;
        error = __assert_func(0,0,0,0);
_L0:
        uVar2 = 0x1e1;
        puVar1 = (undefined1 *)register0x00002008;
      } while (error != ESP_IEEE802154_TX_ERR_COEXIST);
    }
  }
  ezb_plat_radio_transmit_done(&s_radio_ctx,0,uVar2);
  return;
}

