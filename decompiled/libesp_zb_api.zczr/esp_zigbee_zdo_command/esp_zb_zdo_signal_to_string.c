/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_signal_to_string
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * esp_zb_zdo_signal_to_string(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &s_zb_signal_table;
  iVar2 = 0;
  do {
    if (*piVar1 == param_1) {
      return (&PTR__LC2_00011e24)[iVar2 * 2];
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 2;
  } while (iVar2 != 0x22);
  return "UNKNOWN SIGNAL";
}

