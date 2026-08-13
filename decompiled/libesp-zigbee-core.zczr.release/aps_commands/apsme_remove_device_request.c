/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> apsme_remove_device_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int apsme_remove_device_request(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iStack_18;
  int iStack_14;
  
  iVar1 = 2;
  if (param_1 != (int *)0x0) {
    iVar2 = ezb_eui64_is_invalid();
    iVar1 = 2;
    if ((iVar2 == 0) && (iVar2 = ezb_eui64_is_invalid(param_1 + 2), iVar2 == 0)) {
      piVar3 = (int *)nwk_get_extended_address();
      if ((*piVar3 == *param_1) && (piVar3[1] == param_1[1])) {
        apsme_remove_device_indication(param_1);
        iVar1 = 0;
      }
      else {
        iVar2 = zmsg_alloc(0x3c);
        iVar1 = 1;
        if (iVar2 != 0) {
          aps_frame_append_cmd_hdr(0,1,1,0);
          zmsg_append_u8_isra_0(iVar2,7);
          iStack_18 = param_1[2];
          iStack_14 = param_1[3];
          zmsg_append_bytes(iVar2,8,&iStack_18);
          iVar1 = aps_send_cmd(iVar2,param_1);
          if (iVar1 != 0) {
            zmsg_free(iVar2);
          }
        }
      }
    }
  }
  return iVar1;
}

