/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_zcl_general_cmd.o -> cmd_zb_general_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void cmd_zb_general_cmd(uint param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar2 = acquire_row_table();
  if ((int)uVar2 < 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC4,uVar5,&_L0);
    return;
  }
  if (5 < param_1 - 4) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC5,uVar5,&_L0);
    goto _L0;
  }
  iVar6 = uVar2 * 0x2e;
  (&DAT_00010da8)[iVar6] = 1;
  (&DAT_00010da5)[iVar6] = 0;
  *(undefined2 *)(&DAT_00010d88 + iVar6) = 0x104;
  (&DAT_00010da8)[iVar6] = 0;
  cVar1 = parse_address(*param_2,&DAT_00010d7f + iVar6,1);
  (&DAT_00010d7e)[iVar6] = cVar1;
  if (cVar1 == '\0') {
    iVar3 = strcmp((char *)*param_2,"0");
    if (iVar3 != 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,&_L0,&_LC7,uVar5,&_L0);
      goto _L0;
    }
    (&DAT_00010d7e)[iVar6] = 0;
    (&DAT_00010d7f)[iVar6] = 0;
    (&DAT_00010d80)[iVar6] = 0;
  }
  iVar6 = sscan_uint8(param_2[1],&DAT_00010d87 + uVar2 * 0x2e);
  if (iVar6 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC8,uVar5,&_L0);
    goto _L0;
  }
  iVar6 = parse_hex_u16(param_2[2],&DAT_00010d8a + uVar2 * 0x2e);
  if (iVar6 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC9,uVar5,&_L0);
    goto _L0;
  }
  iVar6 = parse_hex_u16(param_2[3],&DAT_00010da6 + uVar2 * 0x2e);
  if (iVar6 == 0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,&_L0,&_LC10,uVar5,&_L0);
    goto _L0;
  }
  if (param_1 != 4) {
    iVar6 = 0x10;
    iVar3 = strcmp((char *)param_2[4],"profile");
    if (iVar3 == 0) {
      if (param_1 < 6) goto _L0;
      iVar6 = parse_hex_u16(param_2[5],&DAT_00010d88 + uVar2 * 0x2e);
      if (iVar6 == 0) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC12,uVar5,&_L0);
        goto _L0;
      }
      if (param_1 == 6) goto _L0;
      iVar6 = 0x18;
      iVar3 = 6;
    }
    else {
      iVar3 = 4;
    }
    param_2 = (undefined4 *)((int)param_2 + iVar6);
    iVar6 = strcmp((char *)*param_2,"payload");
    if (iVar6 == 0) {
      if (param_1 < iVar3 + 2U) goto _L0;
      sVar4 = strlen((char *)param_2[1]);
      if (sVar4 < 0x33) {
        if (sVar4 != 0) goto _L0;
      }
      else {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC14,uVar5,&_L0,0x19);
        sVar4 = 0x32;
_L0:
        if ((sVar4 & 1) != 0) {
          uVar5 = esp_log_timestamp();
          esp_log_write(1,&_L0,&_LC15,uVar5,&_L0);
          goto _L0;
        }
      }
      iVar6 = parse_hex_str(param_2[1],sVar4 & 0xff,&DAT_00010d8c + uVar2 * 0x2e,0x19,0);
      if (iVar6 == 0) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,&_L0,&_LC16,uVar5,&_L0);
        goto _L0;
      }
      (&DAT_00010da5)[uVar2 * 0x2e] = (char)(sVar4 >> 1);
      if (param_1 == iVar3 + 2U) goto _L0;
      param_2 = param_2 + 2;
    }
    iVar6 = strcmp((char *)*param_2,"default");
    if (iVar6 == 0) {
      (&DAT_00010da8)[uVar2 * 0x2e] = 0;
    }
  }
_L0:
  iVar6 = zb_buf_get_out_delayed_ext_func(general_cmd_send,uVar2 & 0xffff,0);
  if (iVar6 == 0) {
    return;
  }
  uVar5 = esp_log_timestamp();
  esp_log_write(1,&_L0,&_LC18,uVar5,&_L0);
_L0:
  invalidate_row(uVar2 & 0xff);
  return;
}

