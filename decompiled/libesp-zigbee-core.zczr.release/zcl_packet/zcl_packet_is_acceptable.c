/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_is_acceptable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_is_acceptable(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0xfe;
  }
  iVar1 = af_endpoint_is_gateway(*(undefined1 *)(param_1 + 0x15));
  if (iVar1 == 0) {
    iVar1 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
    if (iVar1 == 0) {
      return 0x81;
    }
    if (*(short *)(iVar1 + 2) != *(short *)(param_1 + 0x18)) {
      return 0x81;
    }
    iVar1 = zcl_get_cluster_desc
                      (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x16),
                       ((*(byte *)(param_1 + 0x1a) & 8) != 0) + '\x01');
    if (iVar1 == 0) {
      return 0xc3;
    }
  }
  return 0;
}

