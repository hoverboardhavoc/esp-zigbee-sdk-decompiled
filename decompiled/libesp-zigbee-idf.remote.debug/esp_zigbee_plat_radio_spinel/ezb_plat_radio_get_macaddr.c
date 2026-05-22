/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_radio_spinel.o -> ezb_plat_radio_get_macaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void ezb_plat_radio_get_macaddr(uint8_t *macaddr)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_a1;
  
  iVar1 = esp_radio_spinel_get_eui64(0);
  if (iVar1 == 0) {
    uVar2 = __bswapdi2(*(undefined4 *)macaddr,*(undefined4 *)(macaddr + 4));
    *(undefined4 *)macaddr = uVar2;
    *(undefined4 *)(macaddr + 4) = extraout_a1;
    return;
  }
  _esp_error_check_failed
            ("/builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/platform/esp_zigbee_plat_radio_spinel.c"
             ,0x56,"ezb_plat_radio_get_macaddr",
             "esp_radio_spinel_get_eui64(macaddr, ESP_RADIO_SPINEL_ZIGBEE)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

