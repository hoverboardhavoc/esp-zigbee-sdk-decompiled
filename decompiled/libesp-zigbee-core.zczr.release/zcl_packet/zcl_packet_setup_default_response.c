/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_default_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_setup_default_response(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 uStack_11;
  
  if ((param_2 == 0) || (param_1 == 0)) {
_L0:
    uVar1 = 0x87;
  }
  else {
    if ((*(ushort *)(param_2 + 0xc) < 0xfff8) &&
       (((*(byte *)(param_2 + 0x1a) & 3) != 0 || (*(char *)(param_2 + 0x20) != '\v')))) {
      if (param_3 == 0xfe) {
        return 0xfe;
      }
      if (((*(byte *)(param_2 + 0x1a) & 0x10) == 0) || (param_3 != 0)) {
        iVar2 = zcl_packet_setup_response(param_1,param_2,0xb);
        if (iVar2 == 0) {
          *(byte *)(param_1 + 0x1a) = *(byte *)(param_1 + 0x1a) & 0xfc | 0x10;
          if (*(int *)(param_1 + 0x24) != 0) {
            zmsg_set_length(0);
            uStack_11 = *(undefined1 *)(param_2 + 0x20);
            zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),1,&uStack_11);
            uStack_11 = (undefined1)param_3;
            zmsg_append_bytes(*(undefined4 *)(param_1 + 0x24),1,&uStack_11);
            return 0;
          }
          return 0x85;
        }
        goto _L0;
      }
    }
    uVar1 = 0xfe;
  }
  return uVar1;
}

