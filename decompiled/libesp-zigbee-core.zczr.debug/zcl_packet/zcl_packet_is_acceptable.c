/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_is_acceptable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_is_acceptable(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else {
    iVar1 = af_endpoint_is_gateway(*(undefined1 *)(param_1 + 0x15));
    if (iVar1 == 0) {
      iVar1 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
      if (iVar1 == 0) {
        uVar2 = 0x81;
      }
      else if (*(short *)(iVar1 + 2) == *(short *)(param_1 + 0x18)) {
        if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
          uVar2 = 1;
        }
        else {
          uVar2 = 2;
        }
        iVar1 = zcl_get_cluster_desc
                          (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x16),uVar2);
        if (iVar1 == 0) {
          uVar2 = 0xc3;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0x81;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

