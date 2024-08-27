/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_signal_to_string
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
      return (&PTR__L0_000118a0)[iVar2 * 2];
    }
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 2;
  } while (iVar2 != 0x2a);
  return "UNKNOWN SIGNAL";
}

